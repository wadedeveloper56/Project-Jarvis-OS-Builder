#include "pch.h"
#include "common.h"
#include "pdbdump.h"

static char MagicStg[]           = "Microsoft C/C++ MSF 7.00\r\n";
static unsigned char MagicTail[] = {0x1A, 0x44, 0x53, 0x00, 0x00, 0x00};

static const char szBigHdrMagic[0x1E] = "Microsoft C/C++ MSF 7.00\r\n\x1a\x44\x53";

static char Magic[] = {"Microsoft C/C++ MSF 7.00\r\n\x1a\x44\x53\x00\x00\x00"};

static char errbuf[1024] = {"\0"};
static char sbuf[1024];
static char* pbgn = 0;

#define MagicLen 32

typedef uint32_t ulittle32_t;
typedef std::vector<ulittle32_t> vU32;

#pragma pack(1)

typedef struct tagSuperBlock
{
    char FileMagic[MagicLen];
    ulittle32_t BlockSize;
    ulittle32_t FreeBlockMapBlock;
    ulittle32_t NumBlocks;
    ulittle32_t NumDirectoryBytes;
    ulittle32_t Unknown;
    ulittle32_t BlockMapAddr;
} SuperBlock, *pSuperBlock;

typedef struct tagStreamDirectory
{
    ulittle32_t NumStreams;
} StreamDirectory, *PSD;

typedef struct tagPdbStreamHeader
{
    ulittle32_t Version;
    ulittle32_t Signature;
    ulittle32_t Age;
    GUID UniqueId;
} PdbStreamHeader, *PSH;

enum class PdbStreamVersion : uint32_t
{
    VC2     = 19941610,
    VC4     = 19950623,
    VC41    = 19950814,
    VC50    = 19960307,
    VC98    = 19970604,
    VC70Dep = 19990604,
    VC70    = 20000404,
    VC80    = 20030901,
    VC110   = 20091201,
    VC140   = 20140508
};

typedef struct tagTpiStreamHeader
{
    uint32_t Version;
    uint32_t HeaderSize;
    uint32_t TypeIndexBegin;
    uint32_t TypeIndexEnd;
    uint32_t TypeRecordBytes;

    uint16_t HashStreamIndex;
    uint16_t HashAuxStreamIndex;
    uint32_t HashKeySize;
    uint32_t NumHashBuckets;

    int32_t HashValueBufferOffset;
    uint32_t HashValueBufferLength;

    int32_t IndexOffsetBufferOffset;
    uint32_t IndexOffsetBufferLength;

    int32_t HashAdjBufferOffset;
    uint32_t HashAdjBufferLength;
} TpiStreamHeader, *PTPI;

enum class TpiStreamVersion : uint32_t
{
    V40 = 19950410,
    V41 = 19951122,
    V50 = 19961031,
    V70 = 19990903,
    V80 = 20040203
};

typedef struct tagDbiStreamHeader
{
    int32_t VersionSignature;
    uint32_t VersionHeader;
    uint32_t Age;
    uint16_t GlobalStreamIndex;
    uint16_t BuildNumber;
    uint16_t PublicStreamIndex;
    uint16_t PdbDllVersion;
    uint16_t SymRecordStream;
    uint16_t PdbDllRbld;
    int32_t ModInfoSize;
    int32_t SectionContributionSize;
    int32_t SectionMapSize;
    int32_t SourceInfoSize;
    int32_t TypeServerMapSize;
    uint32_t MFCTypeServerIndex;
    int32_t OptionalDbgHeaderSize;
    int32_t ECSubstreamSize;
    uint16_t Flags;
    uint16_t Machine;
    uint32_t Padding;
} DbiStreamHeader, *PDBI;

enum class DbiStreamVersion : uint32_t
{
    VC41 = 930803,
    V50  = 19960307,
    V60  = 19970606,
    V70  = 19990903,
    V110 = 20091201
};

struct ModiStream
{
    uint32_t Signature;
    uint32_t GlobalRefsSize;
};

void
show_stream_header(char* cp)
{
    ulittle32_t v, s, a;
    char* pb      = sbuf;
    PSH psh       = (PSH) cp;
    PTPI ptpi     = (PTPI) cp;
    uint32_t size = ptpi->HeaderSize;

    if (size == sizeof(TpiStreamHeader))
    {
        v = ptpi->Version;
        sprintf(
            pb,
            "\nTpi Stream Header: ver %u\n",
            v
            );
        direct_out_it(pb);

        return;
    }

    v = psh->Version;
    s = psh->Signature;
    a = psh->Age;
    sprintf(
        pb,
        "\nStream Header: ver %u, sig %u, age %u\n",
        v,
        s,
        a
        );
    direct_out_it(pb);
    HexDump(
        (PBYTE) &psh->UniqueId,
        sizeof(GUID),
        (PBYTE) pbgn
        );
}

int
add_2_seen(
    ulittle32_t val,
    vU32& seen
    )
{
    ulittle32_t tst;
    size_t ii, max = seen.size();

    for (ii = 0; ii < max; ii++)
    {
        tst = seen[ii];

        if (tst == val)
        {
            return 0;
        }
    }

    seen.push_back(val);

    return 1;
}

int
IsPdbFile(
    char* in_cp,
    unsigned long long len
    )
{
    char* pb  = sbuf;
    char* lpe = errbuf;
    ulittle32_t bma, ndb, num, bs, val, cnt, nos, blks, tot, j, k;
    __int64 off;
    ulittle32_t* arr;

    if (len < 4096)
    {
        sprintf(
            lpe,
            "Error: Lenght %llu given less than 1 block of 4096!\n",
            len
            );

        return 0;
    }

    pbgn = in_cp;
    pSuperBlock psb           = (pSuperBlock) in_cp;
    unsigned long long i, max = MagicLen;
    char c1, c2;
    char* cp = &psb->FileMagic[0];

    for (i = 0; i < max; i++)
    {
        c1 = cp[i];
        c2 = Magic[i];

        if (c1 != c2)
        {
            sprintf(
                lpe,
                "Error: Offset %llu Magic chars do not mactch - %c vs %c!\n",
                i,
                c1,
                c2
                );

            return 0;
        }
    }

    strcpy(
        pb,
        "Offset 000000 - Got Magic PDB header\n"
        );
    direct_out_it(pb);
    HexDump(
        (PBYTE) cp,
        64,
        (PBYTE) in_cp
        );

    bs = psb->BlockSize;

    if (bs != 4096)
    {
        sprintf(
            lpe,
            "Error: Only support Block size of 4096, got %u!\n",
            bs
            );

        return 0;
    }

    strcpy(
        pb,
        "...\n"
        );
    direct_out_it(pb);
    cp += (bs - 32);
    HexDump(
        (PBYTE) cp,
        32,
        (PBYTE) in_cp
        );
    sprintf(
        pb,
        "psb->BlockSize         = % 10u (%08x)\n",
        bs,
        bs
        );
    direct_out_it(pb);

    val = psb->FreeBlockMapBlock;
    sprintf(
        pb,
        "psb->FreeBlockMapBlock = % 10u (%08x)\n",
        val,
        val
        );
    direct_out_it(pb);

    num = psb->NumBlocks;
    sprintf(
        pb,
        "psb->NumBlocks         = % 10u (%08x)\n",
        num,
        num
        );
    direct_out_it(pb);

    if ((num * bs) != len)
    {
        sprintf(
            lpe,
            "Error: Number of blocks, %u, times block size %u, NOT equal file size %llu\n",
            num,
            bs,
            len
            );

        return 0;
    }

    ndb = psb->NumDirectoryBytes;
    sprintf(
        pb,
        "psb->NumDirectoryBytes = % 10u (%08x)\n",
        ndb,
        ndb
        );
    direct_out_it(pb);

    arr = &psb->BlockMapAddr;
    bma = psb->BlockMapAddr;

    if ((bma == 0) || (bma >= num))
    {
        sprintf(
            lpe,
            "Error: BlockMapAddr %u, is zero or GTE number of block %u!\n",
            bma,
            num
            );

        return 0;
    }

    sprintf(
        pb,
        "psb->BlockMapAddr      = % 10u (%08x)\n",
        bma,
        bma
        );
    direct_out_it(pb);
    HexDump(
        (PBYTE) arr,
        32,
        (PBYTE) in_cp
        );

    cp = in_cp + (bs * (bma - 1));
    PSD psd = (PSD) cp;
    arr = (ulittle32_t*) cp;
    nos = psd->NumStreams;
    sprintf(
        pb,
        "\npsd->NumStreams        = % 10u (%08x)\n",
        nos,
        nos
        );
    direct_out_it(pb);
    arr++;
    vU32 v;
    vU32 b;
    vU32 seen;
    tot = 0;

    for (cnt = 0; cnt < nos; cnt++)
    {
        val = *arr;
        v.push_back(val);
        blks = 1 + (ulittle32_t) ceil(val / bs);
        b.push_back(blks);
        tot += blks;
        sprintf(
            pb,
            "  Stream % 3u: size % 10u (%08x), blocks %u\n",
            (cnt + 1),
            val,
            val,
            blks
            );
        direct_out_it(pb);
        arr++;
    }

    sprintf(
        pb,
        "Total Stream Blocks: % 10u (%08x)\n",
        tot,
        tot
        );
    direct_out_it(pb);

    for (cnt = 0; cnt < nos; cnt++)
    {
        blks = b[cnt];
        sprintf(
            pb,
            "  Stream % 3u:% 3u: {",
            (cnt + 1),
            blks
            );
        direct_out_it(pb);

        for (j = 0; j < blks; j++)
        {
            val = *arr;

            if (
                (val < num) && add_2_seen(
                    val,
                    seen
                    )
                )
            {
                sprintf(
                    pb,
                    " %u",
                    val
                    );
                direct_out_it(pb);
            }
            else
            {
                if (val < num)
                {
                    sprintf(
                        lpe,
                        "Error: Have a DUPLICTED block index %u!",
                        val
                        );
                }
                else
                {
                    sprintf(
                        lpe,
                        "Error: Block index %u GTE max blocks %u!",
                        val,
                        num
                        );
                }

                return 0;
            }

            arr++;
        }

        strcpy(
            pb,
            " }\n"
            );
        direct_out_it(pb);
    }

    off = (char*) arr - (char*) psd;
    sprintf(
        pb,
        "StreamDirectory block consumed %llu bytes (ndb=%u)\n",
        off,
        ndb
        );
    direct_out_it(pb);
    HexDump(
        (PBYTE) arr,
        32,
        (PBYTE) in_cp
        );

    for (cnt = 1; cnt < num; cnt++)
    {
        cp  = in_cp + (bs * cnt);
        off = cp - in_cp;
        sprintf(
            pb,
            "\nOffset %08llX - block %u\n",
            off,
            (cnt + 1)
            );
        direct_out_it(pb);
        HexDump(
            (PBYTE) cp,
            32,
            (PBYTE) in_cp
            );
        strcpy(
            pb,
            "...\n"
            );
        direct_out_it(pb);
        cp += (bs - 32);
        HexDump(
            (PBYTE) cp,
            32,
            (PBYTE) in_cp
            );
    }

    sprintf(
        pb,
        "\nListing %llu Blocks, in the ORDER indicated...\n",
        (unsigned long long) seen.size()
        );
    direct_out_it(pb);

    cnt  = 0;
    blks = b[cnt];
    j    = blks;
    k    = 0;

    for (auto bi : seen)
    {
        k++;
        off = bs * bi;
        cp  = in_cp + off;

        if (k == 1)
        {
            show_stream_header(cp);
        }

        sprintf(
            pb,
            "s:% 3u: Offset %08llX - block % 3u, %u of %u\n",
            (cnt + 1),
            off,
            (bi + 1),
            k,
            j
            );
        direct_out_it(pb);
        HexDump(
            (PBYTE) cp,
            32,
            (PBYTE) in_cp
            );
        strcpy(
            pb,
            "...\n"
            );
        direct_out_it(pb);
        cp += (bs - 32);
        HexDump(
            (PBYTE) cp,
            32,
            (PBYTE) in_cp
            );
        blks--;

        if (blks == 0)
        {
            cnt++;

            if (cnt < nos)
            {
                blks = b[cnt];
                j    = blks;
                k    = 0;
            }
        }
    }

    sprintf(
        pb,
        "\nDone Listing of %llu Blocks, in the ORDER indicated...\n",
        (unsigned long long) seen.size()
        );
    direct_out_it(pb);

    return 0;
}

int
DumpPdbFile(
    char* cp,
    size_t len
    )
{
    return 0;
}