#include "pch.h"
#include "alink.h"

char t_thred[4];
char f_thred[4];
int t_thredindex[4];
int f_thredindex[4];

void DestroyLIDATA(DataBlockPtr p)
{
	long i;
	if (p->blocks)
	{
		for (i = 0; i < p->blocks; i++)
		{
			DestroyLIDATA(((DataBlockPtrPtr)(p->data))[i]);
		}
	}
	free(p->data);
	free(p);
}

DataBlockPtr BuildLiData(long* bufofs)
{
	DataBlockPtr p;
	long i, j;

	p = (DataBlockPtr)checkMalloc(sizeof(DataBlock));
	i = *bufofs;
	p->dataofs = i - lidata->dataofs;
	p->count = buf[i] + 256 * buf[i + 1];
	i += 2;
	if (rectype == LIDATA32)
	{
		p->count += (buf[i] + 256 * buf[i + 1]) << 16;
		i += 2;
	}
	p->blocks = buf[i] + 256 * buf[i + 1];
	i += 2;
	if (p->blocks)
	{
		p->data = checkMalloc(p->blocks * sizeof(DataBlockPtr));
		for (j = 0; j < p->blocks; j++)
		{
			((DataBlockPtrPtr)p->data)[j] = BuildLiData(&i);
		}
	}
	else
	{
		p->data = checkMalloc(buf[i] + 1);
		((char*)p->data)[0] = buf[i];
		i++;
		for (j = 0; j < ((UCharPtr)p->data)[0]; j++, i++)
		{
			((UCharPtr)p->data)[j + 1] = buf[i];
		}
	}
	*bufofs = i;
	return p;
}

void EmitLiData(DataBlockPtr p, long Segnum, long* ofs)
{
	long i, j;

	for (i = 0; i < p->count; i++)
	{
		if (p->blocks)
		{
			for (j = 0; j < p->blocks; j++)
			{
				EmitLiData(((DataBlockPtrPtr)p->data)[j], Segnum, ofs);
			}
		}
		else
		{
			for (j = 0; j < ((UCharPtr)p->data)[0]; j++, (*ofs)++)
			{
				if ((*ofs) >= Seglist[Segnum]->length)
				{
					ReportError(ERR_INV_DATA);
				}
				if (GetNbit(Seglist[Segnum]->datmask, *ofs))
				{
					if (Seglist[Segnum]->data[*ofs] != ((UCharPtr)p->data)[j + 1])
					{
						ReportError(ERR_OVERWRITE);
					}
				}
				Seglist[Segnum]->data[*ofs] = ((UCharPtr)p->data)[j + 1];
				SetNbit(Seglist[Segnum]->datmask, *ofs);
			}
		}
	}
}

void RelocLIDATA(DataBlockPtr p, long* ofs, RelocPtr r)
{
	long i, j;

	for (i = 0; i < p->count; i++)
	{
		if (p->blocks)
		{
			for (j = 0; j < p->blocks; j++)
			{
				RelocLIDATA(((DataBlockPtrPtr)p->data)[j], ofs, r);
			}
		}
		else
		{
			j = r->ofs - p->dataofs;
			if (j >= 0)
			{
				if ((j < 5) || ((li_le == PREV_LI32) && (j < 7)))
				{
					ReportError(ERR_BAD_FIXUP);
				}
				relocs = (RelocPtrPtr)checkRealloc(relocs, (fixcount + 1) * sizeof(RelocPtr));
				relocs[fixcount] = (RelocPtr)checkMalloc(sizeof(Reloc));
				memcpy(relocs[fixcount], r, sizeof(Reloc));
				relocs[fixcount]->ofs = *ofs + j;
				fixcount++;
				*ofs += ((UCharPtr)p->data)[0];
			}
		}
	}
}

void LoadFIXUP(RelocPtr r, UCharPtr buf, long* p)
{
	long j;
	int thrednum;

	j = *p;

	r->ftype = buf[j] >> 4;
	r->ttype = buf[j] & 0xf;
	r->disp = 0;
	j++;
	if (r->ftype & FIX_THRED)
	{
		thrednum = r->ftype & THRED_MASK;
		if (thrednum > 3)
		{
			ReportError(ERR_BAD_FIXUP);
		}
		r->ftype = (f_thred[thrednum] >> 2) & 7;
		switch (r->ftype)
		{
			case REL_SegFRAME:
			case REL_GRPFRAME:
			case REL_EXTFRAME:
				r->frame = f_thredindex[thrednum];
				if (!r->frame)
				{
					ReportError(ERR_BAD_FIXUP);
				}
				break;
			case REL_LILEFRAME:
			case REL_TARGETFRAME:
				break;
			default:
				ReportError(ERR_BAD_FIXUP);
		}
		switch (r->ftype)
		{
			case REL_SegFRAME:
				r->frame += Segmin - 1;
				break;
			case REL_GRPFRAME:
				r->frame += grpmin - 1;
				break;
			case REL_EXTFRAME:
				r->frame += extmin - 1;
				break;
			case REL_LILEFRAME:
				r->frame = prevSeg;
				break;
			default:
				break;
		}
	}
	else
	{
		switch (r->ftype)
		{
			case REL_SegFRAME:
			case REL_GRPFRAME:
			case REL_EXTFRAME:
				r->frame = GetIndex(buf, &j);
				if (!r->frame)
				{
					ReportError(ERR_BAD_FIXUP);
				}
				break;
			case REL_LILEFRAME:
			case REL_TARGETFRAME:
				break;
			default:
				ReportError(ERR_BAD_FIXUP);
		}
		switch (r->ftype)
		{
			case REL_SegFRAME:
				r->frame += Segmin - 1;
				break;
			case REL_GRPFRAME:
				r->frame += grpmin - 1;
				break;
			case REL_EXTFRAME:
				r->frame += extmin - 1;
				break;
			case REL_LILEFRAME:
				r->frame = prevSeg;
				break;
			default:
				break;
		}
	}
	if (r->ttype & FIX_THRED)
	{
		thrednum = r->ttype & 3;
		if ((r->ttype & 4) == 0) /* P bit not set? */
		{
			r->ttype = (t_thred[thrednum] >> 2) & 3; /* DISP present */
		}
		else
		{
			r->ttype = ((t_thred[thrednum] >> 2) & 3) | 4; /* no disp */
		}
		r->target = t_thredindex[thrednum];
		switch (r->ttype)
		{
			case REL_SegDISP:
			case REL_GRPDISP:
			case REL_EXTDISP:
			case REL_SegONLY:
			case REL_GRPONLY:
			case REL_EXTONLY:
				if (!r->target)
				{
					ReportError(ERR_BAD_FIXUP);
				}
				break;
			case REL_EXPFRAME:
				break;
			default:
				ReportError(ERR_BAD_FIXUP);
		}
		switch (r->ttype)
		{
			case REL_SegDISP:
				r->target += Segmin - 1;
				break;
			case REL_GRPDISP:
				r->target += grpmin - 1;
				break;
			case REL_EXTDISP:
				r->target += extmin - 1;
				break;
			case REL_EXPFRAME:
				break;
			case REL_SegONLY:
				r->target += Segmin - 1;
				break;
			case REL_GRPONLY:
				r->target += grpmin - 1;
				break;
			case REL_EXTONLY:
				r->target += extmin - 1;
				break;
		}
	}
	else
	{
		r->target = GetIndex(buf, &j);
		switch (r->ttype)
		{
			case REL_SegDISP:
			case REL_GRPDISP:
			case REL_EXTDISP:
			case REL_SegONLY:
			case REL_GRPONLY:
			case REL_EXTONLY:
				if (!r->target)
				{
					ReportError(ERR_BAD_FIXUP);
				}
				break;
			case REL_EXPFRAME:
				break;
			default:
				ReportError(ERR_BAD_FIXUP);
		}
		switch (r->ttype)
		{
			case REL_SegDISP:
				r->target += Segmin - 1;
				break;
			case REL_GRPDISP:
				r->target += grpmin - 1;
				break;
			case REL_EXTDISP:
				r->target += extmin - 1;
				break;
			case REL_EXPFRAME:
				break;
			case REL_SegONLY:
				r->target += Segmin - 1;
				break;
			case REL_GRPONLY:
				r->target += grpmin - 1;
				break;
			case REL_EXTONLY:
				r->target += extmin - 1;
				break;
		}
	}
	switch (r->ttype)
	{
		case REL_SegDISP:
		case REL_GRPDISP:
		case REL_EXTDISP:
		case REL_EXPFRAME:
			r->disp = buf[j] + buf[j + 1] * 256;
			j += 2;
			if (rectype == FIXUPP32)
			{
				r->disp += (buf[j] + buf[j + 1] * 256) << 16;
				j += 2;
			}
			break;
		default:
			break;
	}
	if ((r->ftype == REL_TARGETFRAME) && ((r->ttype & FIX_THRED) == 0))
	{
		switch (r->ttype)
		{
			case REL_SegDISP:
			case REL_GRPDISP:
			case REL_EXTDISP:
			case REL_EXPFRAME:
				r->ftype = r->ttype;
				r->frame = r->target;
				break;
			case REL_SegONLY:
			case REL_GRPONLY:
			case REL_EXTONLY:
				r->ftype = r->ttype - 4;
				r->frame = r->target;
				break;
		}
	}

	*p = j;
}

long loadmod(FILE* objfile)
{
	long modpos;
	long done;
	long i, j, k;
	long Segnum, grpnum;
	RelocPtr r;
	PublicPtr pubdef;
	CharPtr name, aliasName;
	SortEntryPtr listnode;

	modpos = 0;
	done = 0;
	li_le = 0;
	lidata = 0;

	while (!done)
	{
		if (fread(buf, 1, 3, objfile) != 3)
		{
			ReportError(ERR_NO_MODEND);
		}
		rectype = buf[0];
		reclength = buf[1] + 256 * buf[2];
		if (fread(buf, 1, reclength, afile) != reclength)
		{
			ReportError(ERR_NO_RECDATA);
		}
		reclength--; /* remove checksum */
		if ((!modpos) && (rectype != THEADR) && (rectype != LHEADR))
		{
			ReportError(ERR_NO_HEADER);
		}
		switch (rectype)
		{
			case THEADR:
			case LHEADR:
				if (modpos)
				{
					ReportError(ERR_EXTRA_HEADER);
				}
				modname = (CharPtrPtr)checkRealloc(modname, (nummods + 1) * sizeof(CharPtr));
				modname[nummods] = (CharPtr)checkMalloc(buf[0] + 1);
				for (i = 0; i < buf[0]; i++)
				{
					modname[nummods][i] = buf[i + 1];
				}
				modname[nummods][i] = 0;
				strupr(modname[nummods]);
				/*	    printf("Loading module %s\n",modname[nummods]);*/
				if ((buf[0] + 1) != reclength)
				{
					ReportError(ERR_EXTRA_DATA);
				}
				namemin = namecount;
				Segmin = Segcount;
				extmin = extcount;
				fixmin = fixcount;
				grpmin = grpcount;
				impmin = impcount;
				expmin = expcount;
				commin = comcount;
				nummods++;
				break;
			case COMENT:
				li_le = 0;
				if (lidata)
				{
					DestroyLIDATA(lidata);
					lidata = 0;
				}
				if (reclength >= 2)
				{
					switch (buf[1])
					{
						case COMENT_LIB_SPEC:
						case COMENT_DEFLIB:
							filename = (CharPtrPtr)checkRealloc(filename, (filecount + 1) * sizeof(CharPtr));
							filename[filecount] = (CharPtr)checkMalloc(reclength - 1 + 4);
							/* get filename */
							for (i = 0; i < reclength - 2; i++)
							{
								filename[filecount][i] = buf[i + 2];
							}
							filename[filecount][reclength - 2] = 0;
							for (i = strlen(filename[filecount]) - 1;
								(i >= 0) && (filename[filecount][i] != PATH_CHAR);
								i--)
							{
								if (filename[filecount][i] == '.') break;
							}
							if (((i >= 0) && (filename[filecount][i] != '.')) || (i < 0))
							{
								strcat(filename[filecount], ".lib");
							}
							/* add default library to file list */
							filecount++;
							break;
						case COMENT_OMFEXT:
							if (reclength < 4)
							{
								ReportError(ERR_INVALID_COMENT);
							}
							switch (buf[2])
							{
								case EXT_IMPDEF:
									j = 4;
									if (reclength < (j + 4))
									{
										ReportError(ERR_INVALID_COMENT);
									}
									impdefs = (ImpRecPtr)checkRealloc(impdefs, (impcount + 1) * sizeof(ImpRec));
									impdefs[impcount].flags = buf[3];
									impdefs[impcount].int_name = (CharPtr)checkMalloc(buf[j] + 1);
									for (i = 0; i < buf[j]; i++)
									{
										impdefs[impcount].int_name[i] = buf[j + i + 1];
									}
									j += buf[j] + 1;
									impdefs[impcount].int_name[i] = 0;
									if (!case_sensitive)
									{
										strupr(impdefs[impcount].int_name);
									}
									impdefs[impcount].mod_name = (CharPtr)checkMalloc(buf[j] + 1);
									for (i = 0; i < buf[j]; i++)
									{
										impdefs[impcount].mod_name[i] = buf[j + i + 1];
									}
									j += buf[j] + 1;
									impdefs[impcount].mod_name[i] = 0;
									if (!case_sensitive)
									{
										strupr(impdefs[impcount].mod_name);
									}
									if (impdefs[impcount].flags)
									{
										impdefs[impcount].ordinal = buf[j] + 256 * buf[j + 1];
										j += 2;
									}
									else
									{
										if (buf[j])
										{
											impdefs[impcount].imp_name = (CharPtr)checkMalloc(buf[j] + 1);
											for (i = 0; i < buf[j]; i++)
											{
												impdefs[impcount].imp_name[i] = buf[j + i + 1];
											}
											j += buf[j] + 1;
											impdefs[impcount].imp_name[i] = 0;
										}
										else
										{
											impdefs[impcount].imp_name = (CharPtr)checkMalloc(strlen(impdefs[impcount].int_name) + 1);
											strcpy(impdefs[impcount].imp_name, impdefs[impcount].int_name);
										}
									}
									impcount++;
									break;
								case EXT_EXPDEF:
									expdefs = (ExpRecPtr)checkRealloc(expdefs, (expcount + 1) * sizeof(ExpRec));
									j = 4;
									expdefs[expcount].flags = buf[3];
									expdefs[expcount].pubdef = NULL;
									expdefs[expcount].exp_name = (CharPtr)checkMalloc(buf[j] + 1);
									for (i = 0; i < buf[j]; i++)
									{
										expdefs[expcount].exp_name[i] = buf[j + i + 1];
									}
									expdefs[expcount].exp_name[buf[j]] = 0;
									if (!case_sensitive)
									{
										strupr(expdefs[expcount].exp_name);
									}
									j += buf[j] + 1;
									if (buf[j])
									{
										expdefs[expcount].int_name = (CharPtr)checkMalloc(buf[j] + 1);
										for (i = 0; i < buf[j]; i++)
										{
											expdefs[expcount].int_name[i] = buf[j + i + 1];
										}
										expdefs[expcount].int_name[buf[j]] = 0;
										if (!case_sensitive)
										{
											strupr(expdefs[expcount].int_name);
										}
									}
									else
									{
										expdefs[expcount].int_name = (CharPtr)checkMalloc(strlen(expdefs[expcount].exp_name) + 1);
										strcpy(expdefs[expcount].int_name, expdefs[expcount].exp_name);
									}
									j += buf[j] + 1;
									if (expdefs[expcount].flags & EXP_ORD)
									{
										expdefs[expcount].ordinal = buf[j] + 256 * buf[j + 1];
									}
									else
									{
										expdefs[expcount].ordinal = 0;
									}
									expcount++;
									break;
								default:
									ReportError(ERR_INVALID_COMENT);
							}
							break;
						case COMENT_DOSSeg:
							break;
						case COMENT_TRANSLATOR:
						case COMENT_INTEL_COPYRIGHT:
						case COMENT_MSDOS_VER:
						case COMENT_MEMMODEL:
						case COMENT_NEWOMF:
						case COMENT_LINKPASS:
						case COMENT_LIBMOD:
						case COMENT_EXESTR:
						case COMENT_INCERR:
						case COMENT_NOPAD:
						case COMENT_WKEXT:
						case COMENT_LZEXT:
						case COMENT_PHARLAP:
						case COMENT_IBM386:
						case COMENT_RECORDER:
						case COMENT_COMMENT:
						case COMENT_COMPILER:
						case COMENT_DATE:
						case COMENT_TIME:
						case COMENT_USER:
						case COMENT_DEPFILE:
						case COMENT_COMMANDLINE:
						case COMENT_PUBTYPE:
						case COMENT_COMPARAM:
						case COMENT_TYPDEF:
						case COMENT_STRUCTMEM:
						case COMENT_OPENSCOPE:
						case COMENT_LOCAL:
						case COMENT_ENDSCOPE:
						case COMENT_SOURCEFILE:
							break;
						default:
							printf("COMENT Record (unknown type %02X)\n", buf[1]);
							break;
					}
				}
				break;
			case LLNAMES:
			case LNAMES:
				j = 0;
				while (j < reclength)
				{
					namelist = (CharPtrPtr)checkRealloc(namelist, (namecount + 1) * sizeof(CharPtr));
					namelist[namecount] = (CharPtr)checkMalloc(buf[j] + 1);
					for (i = 0; i < buf[j]; i++)
					{
						namelist[namecount][i] = buf[j + i + 1];
					}
					namelist[namecount][buf[j]] = 0;
					if (!case_sensitive)
					{
						strupr(namelist[namecount]);
					}
					j += buf[j] + 1;
					namecount++;
				}
				break;
			case SegDEF:
			case SegDEF32:
				Seglist = (SegPtrPtr)checkRealloc(Seglist, (Segcount + 1) * sizeof(SegPtr));
				Seglist[Segcount] = (SegPtr)checkMalloc(sizeof(Seg));
				Seglist[Segcount]->attr = buf[0];
				j = 1;
				if ((Seglist[Segcount]->attr & Seg_ALIGN) == Seg_ABS)
				{
					Seglist[Segcount]->absframe = buf[j] + 256 * buf[j + 1];
					Seglist[Segcount]->absofs = buf[j + 2];
					j += 3;
				}
				Seglist[Segcount]->length = buf[j] + 256 * buf[j + 1];
				j += 2;
				if (rectype == SegDEF32)
				{
					Seglist[Segcount]->length += (buf[j] + 256 * buf[j + 1]) << 16;
					j += 2;
				}
				if (Seglist[Segcount]->attr & Seg_BIG)
				{
					if (rectype == SegDEF)
					{
						Seglist[Segcount]->length += 65536;
					}
					else
					{
						if ((Seglist[Segcount]->attr & Seg_ALIGN) != Seg_ABS)
						{
							ReportError(ERR_Seg_TOO_LARGE);
						}
					}
				}
				Seglist[Segcount]->nameindex = GetIndex(buf, &j) - 1;
				Seglist[Segcount]->classindex = GetIndex(buf, &j) - 1;
				Seglist[Segcount]->overlayindex = GetIndex(buf, &j) - 1;
				Seglist[Segcount]->orderindex = -1;
				if (Seglist[Segcount]->nameindex >= 0)
				{
					Seglist[Segcount]->nameindex += namemin;
				}
				if (Seglist[Segcount]->classindex >= 0)
				{
					Seglist[Segcount]->classindex += namemin;
				}
				if (Seglist[Segcount]->overlayindex >= 0)
				{
					Seglist[Segcount]->overlayindex += namemin;
				}
				if ((Seglist[Segcount]->attr & Seg_ALIGN) != Seg_ABS)
				{
					Seglist[Segcount]->data = (UCharPtr)checkMalloc(Seglist[Segcount]->length);
					Seglist[Segcount]->datmask = (UCharPtr)checkMalloc((Seglist[Segcount]->length + 7) / 8);
					for (i = 0; i < (Seglist[Segcount]->length + 7) / 8; i++)
					{
						Seglist[Segcount]->datmask[i] = 0;
					}
				}
				else
				{
					Seglist[Segcount]->data = 0;
					Seglist[Segcount]->datmask = 0;
					Seglist[Segcount]->attr &= (0xffff - Seg_COMBINE);
					Seglist[Segcount]->attr |= Seg_PRIVATE;
				}
				switch (Seglist[Segcount]->attr & Seg_COMBINE)
				{
					case Seg_PRIVATE:
					case Seg_PUBLIC:
					case Seg_PUBLIC2:
					case Seg_COMMON:
					case Seg_PUBLIC3:
						break;
					case Seg_STACK:
						/* stack Segs are always byte aligned */
						Seglist[Segcount]->attr &= (0xffff - Seg_ALIGN);
						Seglist[Segcount]->attr |= Seg_BYTE;
						break;
					default:
						ReportError(ERR_BAD_SegDEF);
						break;
				}
				if ((Seglist[Segcount]->attr & Seg_ALIGN) == Seg_BADALIGN)
				{
					ReportError(ERR_BAD_SegDEF);
				}
				if ((Seglist[Segcount]->classindex >= 0) &&
					(!stricmp(namelist[Seglist[Segcount]->classindex], "CODE") ||
						!stricmp(namelist[Seglist[Segcount]->classindex], "TEXT")))
				{
					/* code Segment */
					Seglist[Segcount]->winFlags = WINF_CODE | WINF_INITDATA | WINF_EXECUTE | WINF_READABLE | WINF_NEG_FLAGS;
				}
				else    /* data Segment */
					Seglist[Segcount]->winFlags = WINF_INITDATA | WINF_READABLE | WINF_WRITEABLE | WINF_NEG_FLAGS;

				if (!stricmp(namelist[Seglist[Segcount]->nameindex], "$$SYMBOLS") ||
					!stricmp(namelist[Seglist[Segcount]->nameindex], "$$TYPES"))
				{
					Seglist[Segcount]->winFlags |= WINF_REMOVE;
				}
				Segcount++;
				break;
			case LEDATA:
			case LEDATA32:
				j = 0;
				prevSeg = GetIndex(buf, &j) - 1;
				if (prevSeg < 0)
				{
					ReportError(ERR_INV_Seg);
				}
				prevSeg += Segmin;
				if ((Seglist[prevSeg]->attr & Seg_ALIGN) == Seg_ABS)
				{
					ReportError(ERR_ABS_Seg);
				}
				prevofs = buf[j] + (buf[j + 1] << 8);
				j += 2;
				if (rectype == LEDATA32)
				{
					prevofs += (buf[j] + (buf[j + 1] << 8)) << 16;
					j += 2;
				}
				for (k = 0; j < reclength; j++, k++)
				{
					if ((prevofs + k) >= Seglist[prevSeg]->length)
					{
						ReportError(ERR_INV_DATA);
					}
					if (GetNbit(Seglist[prevSeg]->datmask, prevofs + k))
					{
						if (Seglist[prevSeg]->data[prevofs + k] != buf[j])
						{
							printf("%08lX: %08lX: %i, %li,%li,%li\n", prevofs + k, j, GetNbit(Seglist[prevSeg]->datmask, prevofs + k), Segcount, Segmin, prevSeg);
							ReportError(ERR_OVERWRITE);
						}
					}
					Seglist[prevSeg]->data[prevofs + k] = buf[j];
					SetNbit(Seglist[prevSeg]->datmask, prevofs + k);
				}
				li_le = PREV_LE;
				break;
			case LIDATA:
			case LIDATA32:
				if (lidata)
				{
					DestroyLIDATA(lidata);
				}
				j = 0;
				prevSeg = GetIndex(buf, &j) - 1;
				if (prevSeg < 0)
				{
					ReportError(ERR_INV_Seg);
				}
				prevSeg += Segmin;
				if ((Seglist[prevSeg]->attr & Seg_ALIGN) == Seg_ABS)
				{
					ReportError(ERR_ABS_Seg);
				}
				prevofs = buf[j] + (buf[j + 1] << 8);
				j += 2;
				if (rectype == LIDATA32)
				{
					prevofs += (buf[j] + (buf[j + 1] << 8)) << 16;
					j += 2;
				}
				lidata = (DataBlockPtr)checkMalloc(sizeof(DataBlock));
				lidata->data = checkMalloc(sizeof(DataBlockPtr) * (1024 / sizeof(DataBlock) + 1));
				lidata->blocks = 0;
				lidata->dataofs = j;
				for (i = 0; j < reclength; i++)
				{
					((DataBlockPtrPtr)lidata->data)[i] = BuildLiData(&j);
				}
				lidata->blocks = i;
				lidata->count = 1;

				k = prevofs;
				EmitLiData(lidata, prevSeg, &k);
				li_le = (rectype == LIDATA) ? PREV_LI : PREV_LI32;
				break;
			case LPUBDEF:
			case LPUBDEF32:
			case PUBDEF:
			case PUBDEF32:
				j = 0;
				grpnum = GetIndex(buf, &j) - 1;
				if (grpnum >= 0)
				{
					grpnum += grpmin;
				}
				Segnum = GetIndex(buf, &j) - 1;
				if (Segnum < 0)
				{
					j += 2;
				}
				else
				{
					Segnum += Segmin;
				}
				for (; j < reclength;)
				{
					pubdef = (PublicPtr)checkMalloc(sizeof(Public));
					pubdef->aliasName = NULL;
					pubdef->grpnum = grpnum;
					pubdef->Segnum = Segnum;
					name = (CharPtr)checkMalloc(buf[j] + 1);
					k = buf[j];
					j++;
					for (i = 0; i < k; i++)
					{
						name[i] = buf[j];
						j++;
					}
					name[i] = 0;
					if (!case_sensitive)
					{
						strupr(name);
					}
					pubdef->ofs = buf[j] + 256 * buf[j + 1];
					j += 2;
					if ((rectype == PUBDEF32) || (rectype == LPUBDEF32))
					{
						pubdef->ofs += (buf[j] + 256 * buf[j + 1]) << 16;
						j += 2;
					}
					pubdef->typenum = GetIndex(buf, &j);
					if (rectype == LPUBDEF || rectype == LPUBDEF32)
					{
						pubdef->modnum = nummods;
					}
					else
					{
						pubdef->modnum = 0;
					}
					if (listnode = binarySearch(publics, pubcount, name))
					{
						for (i = 0; i < listnode->count; i++)
						{
							if (((PublicPtr)listnode->object[i])->modnum == pubdef->modnum)
							{
								if (!((PublicPtr)listnode->object[i])->aliasName)
								{
									printf("Duplicate public symbol %s\n", name);
									exit(1);
								}
								free(((PublicPtr)listnode->object[i])->aliasName);
								(*((PublicPtr)listnode->object[i])) = (*pubdef);
								pubdef = NULL;
								break;
							}
						}
					}
					if (pubdef)
					{
						sortedInsert(&publics, &pubcount, name, pubdef);
					}
					free(name);
				}
				break;
			case LEXTDEF:
			case LEXTDEF32:
			case EXTDEF:
				for (j = 0; j < reclength;)
				{
					externs = (ExtRecPtr)checkRealloc(externs, (extcount + 1) * sizeof(ExtRec));
					externs[extcount].name = (CharPtr)checkMalloc(buf[j] + 1);
					k = buf[j];
					j++;
					for (i = 0; i < k; i++, j++)
					{
						externs[extcount].name[i] = buf[j];
					}
					externs[extcount].name[i] = 0;
					if (!case_sensitive)
					{
						strupr(externs[extcount].name);
					}
					externs[extcount].typenum = GetIndex(buf, &j);
					externs[extcount].pubdef = NULL;
					externs[extcount].flags = EXT_NOMATCH;
					if ((rectype == LEXTDEF) || (rectype == LEXTDEF32))
					{
						externs[extcount].modnum = nummods;
					}
					else
					{
						externs[extcount].modnum = 0;
					}
					extcount++;
				}
				break;
			case GRPDEF:
				grplist = (GroupPtrPtr)checkRealloc(grplist, (grpcount + 1) * sizeof(GroupPtr));
				grplist[grpcount] = (GroupPtr)checkMalloc(sizeof(Group));
				j = 0;
				grplist[grpcount]->nameindex = GetIndex(buf, &j) - 1 + namemin;
				if (grplist[grpcount]->nameindex < namemin)
				{
					ReportError(ERR_BAD_GRPDEF);
				}
				grplist[grpcount]->numSegs = 0;
				while (j < reclength)
				{
					if (buf[j] == 0xff)
					{
						j++;
						i = GetIndex(buf, &j) - 1 + Segmin;
						if (i < Segmin)
						{
							ReportError(ERR_BAD_GRPDEF);
						}
						grplist[grpcount]->Segindex[grplist[grpcount]->numSegs] = i;
						grplist[grpcount]->numSegs++;
					}
					else
					{
						ReportError(ERR_BAD_GRPDEF);
					}
				}
				grpcount++;
				break;
			case FIXUPP:
			case FIXUPP32:
				j = 0;
				while (j < reclength)
				{
					if (buf[j] & 0x80)
					{
						/* FIXUP subrecord */
						if (!li_le)
						{
							ReportError(ERR_BAD_FIXUP);
						}
						r = (RelocPtr)checkMalloc(sizeof(Reloc));
						r->rtype = (buf[j] >> 2);
						r->ofs = buf[j] * 256 + buf[j + 1];
						j += 2;
						r->ofs &= 0x3ff;
						r->rtype ^= FIX_SELFREL;
						r->rtype &= FIX_MASK;
						switch (r->rtype)
						{
							case FIX_LBYTE:
							case FIX_OFS16:
							case FIX_BASE:
							case FIX_PTR1616:
							case FIX_HBYTE:
							case FIX_OFS16_2:
							case FIX_OFS32:
							case FIX_PTR1632:
							case FIX_OFS32_2:
							case FIX_SELF_LBYTE:
							case FIX_SELF_OFS16:
							case FIX_SELF_OFS16_2:
							case FIX_SELF_OFS32:
							case FIX_SELF_OFS32_2:
								break;
							default:
								ReportError(ERR_BAD_FIXUP);
						}
						LoadFIXUP(r, buf, &j);

						if (li_le == PREV_LE)
						{
							r->ofs += prevofs;
							r->Segnum = prevSeg;
							relocs = (RelocPtrPtr)checkRealloc(relocs, (fixcount + 1) * sizeof(RelocPtr));
							relocs[fixcount] = r;
							fixcount++;
						}
						else
						{
							r->Segnum = prevSeg;
							i = prevofs;
							RelocLIDATA(lidata, &i, r);
							free(r);
						}
					}
					else
					{
						/* THRED subrecord */
						i = buf[j]; /* get thred number */
						j++;
						if (i & 0x40) /* Frame? */
						{
							f_thred[i & 3] = i;
							/* get index if required */
							if ((i & 0x1c) < 0xc)
							{
								f_thredindex[i & 3] = GetIndex(buf, &j);
							}
							i &= 3;
						}
						else
						{
							t_thred[i & 3] = i;
							/* target always has index */
							t_thredindex[i & 3] = GetIndex(buf, &j);
						}
					}
				}
				break;
			case BAKPAT:
			case BAKPAT32:
				j = 0;
				if (j < reclength) i = GetIndex(buf, &j);
				i += Segmin - 1;
				if (j < reclength)
				{
					k = buf[j];
					j++;
				}
				while (j < reclength)
				{
					relocs = (RelocPtrPtr)checkRealloc(relocs, (fixcount + 1) * sizeof(RelocPtr));
					relocs[fixcount] = (RelocPtr)checkMalloc(sizeof(Reloc));
					switch (k)
					{
						case 0: relocs[fixcount]->rtype = FIX_SELF_LBYTE; break;
						case 1: relocs[fixcount]->rtype = FIX_SELF_OFS16; break;
						case 2: relocs[fixcount]->rtype = FIX_SELF_OFS32; break;
						default:
							printf("Bad BAKPAT record\n");
							exit(1);
					}
					relocs[fixcount]->ofs = buf[j] + 256 * buf[j + 1];
					j += 2;
					if (rectype == BAKPAT32)
					{
						relocs[fixcount]->ofs += (buf[j] + 256 * buf[j + 1]) << 16;
						j += 2;
					}
					relocs[fixcount]->Segnum = i;
					relocs[fixcount]->target = i;
					relocs[fixcount]->frame = i;
					relocs[fixcount]->ttype = REL_SegDISP;
					relocs[fixcount]->ftype = REL_SegFRAME;
					relocs[fixcount]->disp = buf[j] + 256 * buf[j + 1];
					j += 2;
					if (rectype == BAKPAT32)
					{
						relocs[fixcount]->disp += (buf[j] + 256 * buf[j + 1]) << 16;
						j += 2;
					}
					relocs[fixcount]->disp += relocs[fixcount]->ofs;
					switch (k)
					{
						case 0: relocs[fixcount]->disp++; break;
						case 1: relocs[fixcount]->disp += 2; break;
						case 2: relocs[fixcount]->disp += 4; break;
						default:
							printf("Bad BAKPAT record\n");
							exit(1);
					}
					fixcount++;
				}
				break;
			case LINNUM:
			case LINNUM32:
				printf("LINNUM record\n");
				break;
			case MODEND:
			case MODEND32:
				done = 1;
				if (buf[0] & 0x40)
				{
					if (gotstart)
					{
						ReportError(ERR_MULTIPLE_STARTS);
					}
					gotstart = 1;
					j = 1;
					LoadFIXUP(&startaddr, buf, &j);
					if (startaddr.ftype == REL_LILEFRAME)
					{
						ReportError(ERR_BAD_FIXUP);
					}
				}
				break;
			case COMDEF:
				for (j = 0; j < reclength;)
				{
					externs = (ExtRecPtr)checkRealloc(externs, (extcount + 1) * sizeof(ExtRec));
					externs[extcount].name = (CharPtr)checkMalloc(buf[j] + 1);
					k = buf[j];
					j++;
					for (i = 0; i < k; i++, j++)
					{
						externs[extcount].name[i] = buf[j];
					}
					externs[extcount].name[i] = 0;
					if (!case_sensitive)
					{
						strupr(externs[extcount].name);
					}
					externs[extcount].typenum = GetIndex(buf, &j);
					externs[extcount].pubdef = NULL;
					externs[extcount].flags = EXT_NOMATCH;
					externs[extcount].modnum = 0;
					if (buf[j] == 0x61)
					{
						j++;
						i = buf[j];
						j++;
						if (i == 0x81)
						{
							i = buf[j] + 256 * buf[j + 1];
							j += 2;
						}
						else if (i == 0x84)
						{
							i = buf[j] + 256 * buf[j + 1] + 65536 * buf[j + 2];
							j += 3;
						}
						else if (i == 0x88)
						{
							i = buf[j] + 256 * buf[j + 1] + 65536 * buf[j + 2] + (buf[j + 3] << 24);
							j += 4;
						}
						k = i;
						i = buf[j];
						j++;
						if (i == 0x81)
						{
							i = buf[j] + 256 * buf[j + 1];
							j += 2;
						}
						else if (i == 0x84)
						{
							i = buf[j] + 256 * buf[j + 1] + 65536 * buf[j + 2];
							j += 3;
						}
						else if (i == 0x88)
						{
							i = buf[j] + 256 * buf[j + 1] + 65536 * buf[j + 2] + (buf[j + 3] << 24);
							j += 4;
						}
						i *= k;
						k = 1;
					}
					else if (buf[j] == 0x62)
					{
						j++;
						i = buf[j];
						j++;
						if (i == 0x81)
						{
							i = buf[j] + 256 * buf[j + 1];
							j += 2;
						}
						else if (i == 0x84)
						{
							i = buf[j] + 256 * buf[j + 1] + 65536 * buf[j + 2];
							j += 3;
						}
						else if (i == 0x88)
						{
							i = buf[j] + 256 * buf[j + 1] + 65536 * buf[j + 2] + (buf[j + 3] << 24);
							j += 4;
						}
						k = 0;
					}
					else
					{
						printf("Unknown COMDEF data type %02X\n", buf[j]);
						exit(1);
					}
					comdefs = (ComRecPtrPtr)checkRealloc(comdefs, (comcount + 1) * sizeof(ComRecPtr));
					comdefs[comcount] = (ComRecPtr)checkMalloc(sizeof(ComRec));
					comdefs[comcount]->length = i;
					comdefs[comcount]->isFar = k;
					comdefs[comcount]->modnum = 0;
					comdefs[comcount]->name = checkStrdup(externs[extcount].name);
					extcount++;
					comcount++;
				}

				break;
			case COMDAT:
			case COMDAT32:
				printf("ComDat section\n");
				exit(1);

				break;
			case ALIAS:
				printf("ALIAS record\n");
				j = 0;
				name = (CharPtr)checkMalloc(buf[j] + 1);
				k = buf[j];
				j++;
				for (i = 0; i < k; i++)
				{
					name[i] = buf[j];
					j++;
				}
				name[i] = 0;
				if (!case_sensitive)
				{
					strupr(name);
				}
				printf("ALIAS name:%s\n", name);
				aliasName = (CharPtr)checkMalloc(buf[j] + 1);
				k = buf[j];
				j++;
				for (i = 0; i < k; i++)
				{
					aliasName[i] = buf[j];
					j++;
				}
				aliasName[i] = 0;
				if (!case_sensitive)
				{
					strupr(aliasName);
				}
				printf("Substitute name:%s\n", aliasName);
				if (!strlen(name))
				{
					printf("Cannot use alias a blank name\n");
					exit(1);
				}
				if (!strlen(aliasName))
				{
					printf("No Alias name specified for %s\n", name);
					exit(1);
				}
				pubdef = (PublicPtr)checkMalloc(sizeof(Public));
				pubdef->Segnum = -1;
				pubdef->grpnum = -1;
				pubdef->typenum = -1;
				pubdef->ofs = 0;
				pubdef->modnum = 0;
				pubdef->aliasName = aliasName;
				if (listnode = binarySearch(publics, pubcount, name))
				{
					for (i = 0; i < listnode->count; i++)
					{
						if (((PublicPtr)listnode->object[i])->modnum == pubdef->modnum)
						{
							if (((PublicPtr)listnode->object[i])->aliasName)
							{
								printf("Warning, two aliases for %s, using %s\n", name, ((PublicPtr)listnode->object[i])->aliasName);
							}
							free(pubdef->aliasName);
							free(pubdef);
							pubdef = NULL;
							break;
						}
					}
				}
				if (pubdef)
				{
					sortedInsert(&publics, &pubcount, name, pubdef);
				}
				free(name);
				break;
			default:
				ReportError(ERR_UNKNOWN_RECTYPE);
		}
		filepos += 4 + reclength;
		modpos += 4 + reclength;
	}
	if (lidata)
	{
		DestroyLIDATA(lidata);
	}
	return 0;
}

void loadlib(FILE* libfile, CharPtr libname)
{
	unsigned int i, j, k, n;
	CharPtr name;
	unsigned short modpage;
	LibraryFilePtr p;
	UInt numsyms;
	SortEntryPtr symlist;

	libfiles = (LibraryFilePtr)checkRealloc(libfiles, (libcount + 1) * sizeof(LibraryFile));
	p = &libfiles[libcount];

	p->filename = (CharPtr)checkMalloc(strlen(libname) + 1);
	strcpy(p->filename, libname);

	if (fread(buf, 1, 3, libfile) != 3)
	{
		printf("Error reading from file\n");
		exit(1);
	}
	p->blocksize = buf[1] + 256 * buf[2];
	if (fread(buf, 1, p->blocksize, libfile) != p->blocksize)
	{
		printf("Error reading from file\n");
		exit(1);
	}
	p->blocksize += 3;
	p->dicstart = buf[0] + (buf[1] << 8) + (buf[2] << 16) + (buf[3] << 24);
	p->numdicpages = buf[4] + 256 * buf[5];
	p->flags = buf[6];
	p->libtype = 'O';

	fseek(libfile, p->dicstart, SEEK_SET);

	symlist = (SortEntryPtr)checkMalloc(p->numdicpages * 37 * sizeof(SortEntry));

	numsyms = 0;
	for (i = 0; i < p->numdicpages; i++)
	{
		if (fread(buf, 1, 512, libfile) != 512)
		{
			printf("Error reading from file\n");
			exit(1);
		}
		for (j = 0; j < 37; j++)
		{
			k = buf[j] * 2;
			if (k)
			{
				name = (CharPtr)checkMalloc(buf[k] + 1);
				for (n = 0; n < buf[k]; n++)
				{
					name[n] = buf[n + k + 1];
				}
				name[buf[k]] = 0;
				k += buf[k] + 1;
				modpage = buf[k] + 256 * buf[k + 1];
				if (!(p->flags & LIBF_CASESENSITIVE) || !case_sensitive)
				{
					strupr(name);
				}
				if (name[strlen(name) - 1] == '!')
				{
					free(name);
				}
				else
				{
					symlist[numsyms].id = name;
					symlist[numsyms].count = modpage;
					++numsyms;
				}
			}
		}
	}

	qsort(symlist, numsyms, sizeof(SortEntry), sortCompare);
	p->symbols = symlist;
	p->numsyms = numsyms;
	p->modsloaded = 0;
	p->modlist = (UInt*)checkMalloc(sizeof(unsigned short) * numsyms);
	libcount++;
}

void loadlibmod(UInt libnum, UInt modpage)
{
	LibraryFilePtr p;
	FILE* libfile;
	UInt i;

	p = &libfiles[libnum];

	/* don't open a module we've loaded already */
	for (i = 0; i < p->modsloaded; i++)
	{
		if (p->modlist[i] == modpage) return;
	}

	libfile = fopen(p->filename, "rb");
	if (!libfile)
	{
		printf("Error opening file %s\n", p->filename);
		exit(1);
	}
	fseek(libfile, modpage * p->blocksize, SEEK_SET);
	switch (p->libtype)
	{
		case 'O':
			loadmod(libfile);
			break;
		case 'C':
			loadcofflibmod(p, libfile);
			break;
		default:
			printf("Unknown library file format\n");
			exit(1);
	}

	p->modlist[p->modsloaded] = modpage;
	p->modsloaded++;
	fclose(libfile);
}

void loadres(FILE* f)
{
	unsigned char buf[32];
	static unsigned char buf2[32] = { 0,0,0,0,0x20,0,0,0,0xff,0xff,0,0,0xff,0xff,0,0,
				   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	UInt i, j;
	UInt hdrsize, datsize;
	UCharPtr data;
	UCharPtr hdr;

	if (fread(buf, 1, 32, f) != 32)
	{
		printf("Invalid resource file\n");
		exit(1);
	}
	if (memcmp(buf, buf2, 32))
	{
		printf("Invalid resource file\n");
		exit(1);
	}
	printf("Loading Win32 Resource File\n");
	while (!feof(f))
	{
		i = ftell(f);
		if (i & 3)
		{
			fseek(f, 4 - (i & 3), SEEK_CUR);
		}
		i = fread(buf, 1, 8, f);
		if (i == 0 && feof(f)) return;
		if (i != 8)
		{
			printf("Invalid resource file, no header\n");
			exit(1);
		}
		datsize = buf[0] + (buf[1] << 8) + (buf[2] << 16) + (buf[3] << 24);
		hdrsize = buf[4] + (buf[5] << 8) + (buf[6] << 16) + (buf[7] << 24);
		if (hdrsize < 16)
		{
			printf("Invalid resource file, bad header\n");
			exit(1);
		}
		hdr = (UCharPtr)checkMalloc(hdrsize);
		if (fread(hdr, 1, hdrsize - 8, f) != (hdrsize - 8))
		{
			printf("Invalid resource file, missing header\n");
			exit(1);
		}
		/* if this is a NULL resource, then skip */
		if (!datsize && (hdrsize == 32) && !memcmp(buf2 + 8, hdr, 24))
		{
			free(hdr);
			continue;
		}
		if (datsize)
		{
			data = (UCharPtr)checkMalloc(datsize);
			if (fread(data, 1, datsize, f) != datsize)
			{
				printf("Invalid resource file, no data\n");
				exit(1);
			}
		}
		else data = NULL;
		resource = (ResourcePtr)checkRealloc(resource, (rescount + 1) * sizeof(Resource));
		resource[rescount].data = data;
		resource[rescount].length = datsize;
		i = 0;
		hdrsize -= 8;
		if ((hdr[i] == 0xff) && (hdr[i + 1] == 0xff))
		{
			resource[rescount].typename1 = NULL;
			resource[rescount].typeid1 = hdr[i + 2] + 256 * hdr[i + 3];
			i += 4;
		}
		else
		{
			for (j = i; (j < (hdrsize - 1)) && (hdr[j] | hdr[j + 1]); j += 2);
			if (hdr[j] | hdr[j + 1])
			{
				printf("Invalid resource file, bad name\n");
				exit(1);
			}
			resource[rescount].typename1 = (UCharPtr)checkMalloc(j - i + 2);
			memcpy(resource[rescount].typename1, hdr + i, j - i + 2);
			i = j + 5;
			i &= 0xfffffffc;
		}
		if (i > hdrsize)
		{
			printf("Invalid resource file, overflow\n");
			exit(1);
		}
		if ((hdr[i] == 0xff) && (hdr[i + 1] == 0xff))
		{
			resource[rescount].name = NULL;
			resource[rescount].id = hdr[i + 2] + 256 * hdr[i + 3];
			i += 4;
		}
		else
		{
			for (j = i; (j < (hdrsize - 1)) && (hdr[j] | hdr[j + 1]); j += 2);
			if (hdr[j] | hdr[j + 1])
			{
				printf("Invalid resource file,bad name (2)\n");
				exit(1);
			}
			resource[rescount].name = (UCharPtr)checkMalloc(j - i + 2);
			memcpy(resource[rescount].name, hdr + i, j - i + 2);
			i = j + 5;
			i &= 0xfffffffc;
		}
		i += 6; /* point to Language ID */
		if (i > hdrsize)
		{
			printf("Invalid resource file, overflow(2)\n");
			exit(1);
		}
		resource[rescount].languageid = hdr[i] + 256 * hdr[i + 1];
		rescount++;
		free(hdr);
	}
}
