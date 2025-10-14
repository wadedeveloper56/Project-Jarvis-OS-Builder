#include "jasm.h"

static N_word BITS;     /* = # of bits in machine word (must be power of 2)  */
static N_word MODMASK;  /* = BITS - 1 (mask for calculating modulo BITS)     */
static N_word LOGBITS;  /* = ld(BITS) (logarithmus dualis)                   */
static N_word FACTOR;   /* = ld(BITS / 8) (ld of # of bytes)                 */
static N_word LSB = 1;  /* = mask for least significant bit                  */
static N_word MSB;      /* = mask for most significant bit                   */
static N_word LONGBITS; /* = # of bits in unsigned long                      */
static N_word LOG10;    /* = logarithm to base 10 of BITS - 1                */
static N_word EXP10;    /* = largest possible power of 10 in signed int      */
static wordptr BITMASKTAB;

extern N_word BITS;     /* = # of bits in machine word (must be power of 2)  */
extern N_word MODMASK;  /* = BITS - 1 (mask for calculating modulo BITS)     */
extern N_word LOGBITS;

BitVector_from_Dec_static_data* BitVector_from_Dec_static_Boot(N_word bits)
{
    BitVector_from_Dec_static_data* data = (BitVector_from_Dec_static_data*)yasm_xmalloc(sizeof(BitVector_from_Dec_static_data));
    if (bits > 0)
    {
        data->term = BitVector_Create(BITS, FALSE);
        data->base = BitVector_Create(BITS, FALSE);
        data->prod = BitVector_Create(bits, FALSE);
        data->rank = BitVector_Create(bits, FALSE);
        data->temp = BitVector_Create(bits, FALSE);
    }
    else {
        data->term = NULL;
        data->base = NULL;
        data->prod = NULL;
        data->rank = NULL;
        data->temp = NULL;
    }
    return data;
}

N_word BitVector_Size(N_int bits)           /* bit vector size (# of words)  */
{
    N_word size;

    size = bits >> LOGBITS;
    if (bits AND MODMASK) size++;
    return(size);
}

N_word BitVector_Mask(N_int bits)           /* bit vector mask (unused bits) */
{
    N_word mask;

    mask = bits AND MODMASK;
    if (mask) mask = (N_word)~(~0L << mask); else mask = (N_word)~0L;
    return(mask);
}

void BitVector_Block_Store(wordptr addr, charptr buffer, N_int length)
{
    N_word  size = size_(addr);
    N_word  mask = mask_(addr);
    N_word  value;
    N_word  count;

    /* provide translation for independence of endian-ness: */
    if (size > 0)
    {
        while (size-- > 0)
        {
            value = 0;
            for (count = 0; (length > 0) and (count < BITS); count += 8)
            {
                value |= (((N_word)*buffer++) << count); length--;
            }
            *addr++ = value;
        }
        *(--addr) &= mask;
    }
}

wordptr BitVector_Create(N_int bits, boolean clear)         /* malloc        */
{
    N_word  size;
    N_word  mask;
    N_word  bytes;
    wordptr addr;
    wordptr zero;

    size = BitVector_Size(bits);
    mask = BitVector_Mask(bits);
    bytes = (size + BIT_VECTOR_HIDDEN_WORDS) << FACTOR;
    addr = (wordptr)yasm_xmalloc((size_t)bytes);
    if (addr != NULL)
    {
        *addr++ = bits;
        *addr++ = size;
        *addr++ = mask;
        if (clear)
        {
            zero = addr;
            BIT_VECTOR_ZERO_WORDS(zero, size)
        }
    }
    return(addr);
}

static N_word power10(N_word x)
{
    N_word y = 1;
    while (x-- > 0) y *= 10;
    return(y);
}

ErrCode BitVector_Boot(void)
{
    N_long longsample = 1L;
    N_word sample = LSB;
    N_word lsb;

    if (sizeof(N_word) > sizeof(size_t)) return(ErrCode_Type);

    BITS = 1;
    while (sample <<= 1) BITS++;    /* determine # of bits in a machine word */

    if (BITS != (sizeof(N_word) << 3)) return(ErrCode_Bits);

    if (BITS < 16) return(ErrCode_Word);

    LONGBITS = 1;
    while (longsample <<= 1) LONGBITS++;  /* = # of bits in an unsigned long */

    if (BITS > LONGBITS) return(ErrCode_Long);

    LOGBITS = 0;
    sample = BITS;
    lsb = (sample AND LSB);
    while ((sample >>= 1) and (not lsb))
    {
        LOGBITS++;
        lsb = (sample AND LSB);
    }

    if (sample) return(ErrCode_Powr);      /* # of bits is not a power of 2! */

    if (BITS != (LSB << LOGBITS)) return(ErrCode_Loga);

    MODMASK = BITS - 1;
    FACTOR = LOGBITS - 3;  /* ld(BITS / 8) = ld(BITS) - ld(8) = ld(BITS) - 3 */
    MSB = (LSB << MODMASK);

    BITMASKTAB = (wordptr)yasm_xmalloc((size_t)(BITS << FACTOR));

    if (BITMASKTAB == NULL) return(ErrCode_Null);

    for (sample = 0; sample < BITS; sample++)
    {
        BITMASKTAB[sample] = (LSB << sample);
    }

    LOG10 = (N_word)(MODMASK * 0.30103); /* = (BITS - 1) * ( ln 2 / ln 10 ) */
    EXP10 = power10(LOG10);

    return(ErrCode_Ok);
}
