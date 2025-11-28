#include "pch.h"
#include "alink.h"

void fixpubSegs(int src, int dest, UInt shift)
{
	UInt i, j;
	PublicPtr q;

	for (i = 0; i < pubcount; ++i)
	{
		for (j = 0; j < publics[i].count; ++j)
		{
			q = (PublicPtr)publics[i].object[j];
			if (q->Segnum == src)
			{
				q->Segnum = dest;
				q->ofs += shift;
			}
		}
	}
}

void fixpubgrps(int src, int dest)
{
	UInt i, j;
	PublicPtr q;

	for (i = 0; i < pubcount; ++i)
	{
		for (j = 0; j < publics[i].count; ++j)
		{
			q = (PublicPtr)publics[i].object[j];
			if (q->grpnum == src)
			{
				q->grpnum = dest;
			}
		}
	}
}

void combine_Segments(long dest, long src)
{
	UInt k, n;
	UCharPtr p, q;
	long a1, a2;

	k = Seglist[dest]->length;
	switch (Seglist[src]->attr & Seg_ALIGN)
	{
		case Seg_WORD:
			a2 = 2;
			k = (k + 1) & 0xfffffffe;
			break;
		case Seg_PARA:
			a2 = 16;
			k = (k + 0xf) & 0xfffffff0;
			break;
		case Seg_PAGE:
			a2 = 0x100;
			k = (k + 0xff) & 0xffffff00;
			break;
		case Seg_DWORD:
			a2 = 4;
			k = (k + 3) & 0xfffffffc;
			break;
		case Seg_MEMPAGE:
			a2 = 0x1000;
			k = (k + 0xfff) & 0xfffff000;
			break;
		case Seg_8BYTE:
			a2 = 8;
			k = (k + 7) & 0xfffffff8;
			break;
		case Seg_32BYTE:
			a2 = 32;
			k = (k + 31) & 0xffffffe0;
			break;
		case Seg_64BYTE:
			a2 = 64;
			k = (k + 63) & 0xffffffc0;
			break;
		default:
			a2 = 1;
			break;
	}
	switch (Seglist[dest]->attr & Seg_ALIGN)
	{
		case Seg_WORD:
			a1 = 2;
			break;
		case Seg_DWORD:
			a1 = 4;
			break;
		case Seg_8BYTE:
			a1 = 8;
			break;
		case Seg_PARA:
			a1 = 16;
			break;
		case Seg_32BYTE:
			a1 = 32;
			break;
		case Seg_64BYTE:
			a1 = 64;
			break;
		case Seg_PAGE:
			a1 = 0x100;
			break;
		case Seg_MEMPAGE:
			a1 = 0x1000;
			break;
		default:
			a1 = 1;
			break;
	}
	Seglist[src]->base = k;
	p = (UCharPtr)checkMalloc(k + Seglist[src]->length);
	q = (UCharPtr)checkMalloc((k + Seglist[src]->length + 7) / 8);
	for (k = 0; k < Seglist[dest]->length; k++)
	{
		if (GetNbit(Seglist[dest]->datmask, k))
		{
			SetNbit(q, k);
			p[k] = Seglist[dest]->data[k];
		}
		else
		{
			ClearNbit(q, k);
		}
	}
	for (; k < Seglist[src]->base; k++)
	{
		ClearNbit(q, k);
	}
	for (; k < (Seglist[src]->base + Seglist[src]->length); k++)
	{
		if (GetNbit(Seglist[src]->datmask, k - Seglist[src]->base))
		{
			p[k] = Seglist[src]->data[k - Seglist[src]->base];
			SetNbit(q, k);
		}
		else
		{
			ClearNbit(q, k);
		}
	}
	Seglist[dest]->length = k;
	if (a2 > a1) Seglist[dest]->attr = Seglist[src]->attr;
	Seglist[dest]->winFlags |= Seglist[src]->winFlags;
	free(Seglist[dest]->data);
	free(Seglist[src]->data);
	free(Seglist[dest]->datmask);
	free(Seglist[src]->datmask);
	Seglist[dest]->data = p;
	Seglist[dest]->datmask = q;

	fixpubSegs(src, dest, Seglist[src]->base);

	for (k = 0; k < fixcount; k++)
	{
		if (relocs[k]->Segnum == src)
		{
			relocs[k]->Segnum = dest;
			relocs[k]->ofs += Seglist[src]->base;
		}
		if (relocs[k]->ttype == REL_SegDISP)
		{
			if (relocs[k]->target == src)
			{
				relocs[k]->target = dest;
				relocs[k]->disp += Seglist[src]->base;
			}
		}
		else if (relocs[k]->ttype == REL_SegONLY)
		{
			if (relocs[k]->target == src)
			{
				relocs[k]->target = dest;
				relocs[k]->ttype = REL_SegDISP;
				relocs[k]->disp = Seglist[src]->base;
			}
		}
		if ((relocs[k]->ftype == REL_SegFRAME) ||
			(relocs[k]->ftype == REL_LILEFRAME))
		{
			if (relocs[k]->frame == src)
			{
				relocs[k]->frame = dest;
			}
		}
	}

	if (gotstart)
	{
		if (startaddr.ttype == REL_SegDISP)
		{
			if (startaddr.target == src)
			{
				startaddr.target = dest;
				startaddr.disp += Seglist[src]->base;
			}
		}
		else if (startaddr.ttype == REL_SegONLY)
		{
			if (startaddr.target == src)
			{
				startaddr.target = dest;
				startaddr.disp = Seglist[src]->base;
				startaddr.ttype = REL_SegDISP;
			}
		}
		if ((startaddr.ftype == REL_SegFRAME) ||
			(startaddr.ftype == REL_LILEFRAME))
		{
			if (startaddr.frame == src)
			{
				startaddr.frame = dest;
			}
		}
	}

	for (k = 0; k < grpcount; k++)
	{
		if (grplist[k])
		{
			for (n = 0; n < grplist[k]->numSegs; n++)
			{
				if (grplist[k]->Segindex[n] == src)
				{
					grplist[k]->Segindex[n] = dest;
				}
			}
		}
	}

	free(Seglist[src]);
	Seglist[src] = 0;
}

void combine_common(long i, long j)
{
	UInt k, n;
	UCharPtr p, q;

	if (Seglist[j]->length > Seglist[i]->length)
	{
		k = Seglist[i]->length;
		Seglist[i]->length = Seglist[j]->length;
		Seglist[j]->length = k;
		p = Seglist[i]->data;
		q = Seglist[i]->datmask;
		Seglist[i]->data = Seglist[j]->data;
		Seglist[i]->datmask = Seglist[j]->datmask;
	}
	else
	{
		p = Seglist[j]->data;
		q = Seglist[j]->datmask;
	}
	for (k = 0; k < Seglist[j]->length; k++)
	{
		if (GetNbit(q, k))
		{
			if (GetNbit(Seglist[i]->datmask, k))
			{
				if (Seglist[i]->data[k] != p[k])
				{
					ReportError(ERR_OVERWRITE);
				}
			}
			else
			{
				SetNbit(Seglist[i]->datmask, k);
				Seglist[i]->data[k] = p[k];
			}
		}
	}
	free(p);
	free(q);

	fixpubSegs(j, i, 0);

	for (k = 0; k < fixcount; k++)
	{
		if (relocs[k]->Segnum == j)
		{
			relocs[k]->Segnum = i;
		}
		if (relocs[k]->ttype == REL_SegDISP)
		{
			if (relocs[k]->target == j)
			{
				relocs[k]->target = i;
			}
		}
		else if (relocs[k]->ttype == REL_SegONLY)
		{
			if (relocs[k]->target == j)
			{
				relocs[k]->target = i;
			}
		}
		if ((relocs[k]->ftype == REL_SegFRAME) ||
			(relocs[k]->ftype == REL_LILEFRAME))
		{
			if (relocs[k]->frame == j)
			{
				relocs[k]->frame = i;
			}
		}
	}

	if (gotstart)
	{
		if (startaddr.ttype == REL_SegDISP)
		{
			if (startaddr.target == j)
			{
				startaddr.target = i;
			}
		}
		else if (startaddr.ttype == REL_SegONLY)
		{
			if (startaddr.target == j)
			{
				startaddr.target = i;
			}
		}
		if ((startaddr.ftype == REL_SegFRAME) ||
			(startaddr.ftype == REL_LILEFRAME))
		{
			if (startaddr.frame == j)
			{
				startaddr.frame = i;
			}
		}
	}

	for (k = 0; k < grpcount; k++)
	{
		if (grplist[k])
		{
			for (n = 0; n < grplist[k]->numSegs; n++)
			{
				if (grplist[k]->Segindex[n] == j)
				{
					grplist[k]->Segindex[n] = i;
				}
			}
		}
	}

	free(Seglist[j]);
	Seglist[j] = 0;
}

void combine_groups(long i, long j)
{
	long n, m;
	char match;

	for (n = 0; n < grplist[j]->numSegs; n++)
	{
		match = 0;
		for (m = 0; m < grplist[i]->numSegs; m++)
		{
			if (grplist[j]->Segindex[n] == grplist[i]->Segindex[m])
			{
				match = 1;
			}
		}
		if (!match)
		{
			grplist[i]->numSegs++;
			grplist[i]->Segindex[grplist[i]->numSegs] = grplist[j]->Segindex[n];
		}
	}
	free(grplist[j]);
	grplist[j] = 0;

	fixpubgrps(j, i);

	for (n = 0; n < fixcount; n++)
	{
		if (relocs[n]->ftype == REL_GRPFRAME)
		{
			if (relocs[n]->frame == j)
			{
				relocs[n]->frame = i;
			}
		}
		if ((relocs[n]->ttype == REL_GRPONLY) || (relocs[n]->ttype == REL_GRPDISP))
		{
			if (relocs[n]->target == j)
			{
				relocs[n]->target = i;
			}
		}
	}

	if (gotstart)
	{
		if ((startaddr.ttype == REL_GRPDISP) || (startaddr.ttype == REL_GRPONLY))
		{
			if (startaddr.target == j)
			{
				startaddr.target = i;
			}
		}
		if (startaddr.ftype == REL_GRPFRAME)
		{
			if (startaddr.frame == j)
			{
				startaddr.frame = i;
			}
		}
	}
}

void combineBlocks()
{
	long i, j, k;
	char* name;
	long attr;
	UInt count;
	UInt* slist;
	UInt curSeg;

	for (i = 0; i < Segcount; i++)
	{
		if (Seglist[i] && ((Seglist[i]->attr & Seg_ALIGN) != Seg_ABS))
		{
			if (Seglist[i]->winFlags & WINF_COMDAT) continue; /* don't combine ComDat Segments */
			name = namelist[Seglist[i]->nameindex];
			attr = Seglist[i]->attr & (Seg_COMBINE | Seg_USE32);
			switch (attr & Seg_COMBINE)
			{
				case Seg_STACK:
					for (j = i + 1; j < Segcount; j++)
					{
						if (!Seglist[j]) continue;
						if (Seglist[j]->winFlags & WINF_COMDAT) continue;
						if ((Seglist[j]->attr & Seg_ALIGN) == Seg_ABS) continue;
						if ((Seglist[j]->attr & Seg_COMBINE) != Seg_STACK) continue;
						combine_Segments(i, j);
					}
					break;
				case Seg_PUBLIC:
				case Seg_PUBLIC2:
				case Seg_PUBLIC3:
					slist = (UInt*)checkMalloc(sizeof(UInt));
					slist[0] = i;
					/* get list of Segments to combine */
					for (j = i + 1, count = 1; j < Segcount; j++)
					{
						if (!Seglist[j]) continue;
						if (Seglist[j]->winFlags & WINF_COMDAT) continue;
						if ((Seglist[j]->attr & Seg_ALIGN) == Seg_ABS) continue;
						if (attr != (Seglist[j]->attr & (Seg_COMBINE | Seg_USE32))) continue;
						if (strcmp(name, namelist[Seglist[j]->nameindex]) != 0) continue;
						slist = (UInt*)checkRealloc(slist, (count + 1) * sizeof(UInt));
						slist[count] = j;
						count++;
					}
					/* sort them by sortorder */
					for (j = 1; j < count; j++)
					{
						curSeg = slist[j];
						for (k = j - 1; k >= 0; k--)
						{
							if (Seglist[slist[k]]->orderindex < 0) break;
							if (Seglist[curSeg]->orderindex >= 0)
							{
								if (strcmp(namelist[Seglist[curSeg]->orderindex],
									namelist[Seglist[slist[k]]->orderindex]) >= 0) break;
							}
							slist[k + 1] = slist[k];
						}
						k++;
						slist[k] = curSeg;
					}
					/* then combine in that order */
					for (j = 1; j < count; j++)
					{
						combine_Segments(i, slist[j]);
					}
					free(slist);
					break;
				case Seg_COMMON:
					for (j = i + 1; j < Segcount; j++)
					{
						if ((Seglist[j] && ((Seglist[j]->attr & Seg_ALIGN) != Seg_ABS)) &&
							((Seglist[i]->attr & (Seg_ALIGN | Seg_COMBINE | Seg_USE32)) == (Seglist[j]->attr & (Seg_ALIGN | Seg_COMBINE | Seg_USE32)))
							&&
							(strcmp(name, namelist[Seglist[j]->nameindex]) == 0)
							&& !(Seglist[j]->winFlags & WINF_COMDAT)
							)
						{
							combine_common(i, j);
						}
					}
					break;
				default:
					break;
			}
		}
	}

	for (i = 0; i < grpcount; i++)
	{
		if (grplist[i])
		{
			for (j = i + 1; j < grpcount; j++)
			{
				if (!grplist[j]) continue;
				if (strcmp(namelist[grplist[i]->nameindex], namelist[grplist[j]->nameindex]) == 0)
				{
					combine_groups(i, j);
				}
			}
		}
	}
}


