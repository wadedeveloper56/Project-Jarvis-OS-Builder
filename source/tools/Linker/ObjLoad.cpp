#include "pch.h"
#include "Linker.h"
#include "ObjLoad.h"
#include "Util.h"

char t_thred[4];
char f_thred[4];
int t_thredindex[4];
int f_thredindex[4];

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
				*ofs += ((PUCHAR)p->data)[0];
			}
		}
	}
}

void LoadFIXUP(RelocPtr r, char* buf, long* p)
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
			case REL_SEGFRAME:
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
			case REL_SEGFRAME:
				r->frame += segmin - 1;
				break;
			case REL_GRPFRAME:
				r->frame += grpmin - 1;
				break;
			case REL_EXTFRAME:
				r->frame += extmin - 1;
				break;
			case REL_LILEFRAME:
				r->frame = prevseg;
				break;
			default:
				break;
		}
	}
	else
	{
		switch (r->ftype)
		{
			case REL_SEGFRAME:
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
			case REL_SEGFRAME:
				r->frame += segmin - 1;
				break;
			case REL_GRPFRAME:
				r->frame += grpmin - 1;
				break;
			case REL_EXTFRAME:
				r->frame += extmin - 1;
				break;
			case REL_LILEFRAME:
				r->frame = prevseg;
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
			case REL_SEGDISP:
			case REL_GRPDISP:
			case REL_EXTDISP:
			case REL_SEGONLY:
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
			case REL_SEGDISP:
				r->target += segmin - 1;
				break;
			case REL_GRPDISP:
				r->target += grpmin - 1;
				break;
			case REL_EXTDISP:
				r->target += extmin - 1;
				break;
			case REL_EXPFRAME:
				break;
			case REL_SEGONLY:
				r->target += segmin - 1;
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
			case REL_SEGDISP:
			case REL_GRPDISP:
			case REL_EXTDISP:
			case REL_SEGONLY:
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
			case REL_SEGDISP:
				r->target += segmin - 1;
				break;
			case REL_GRPDISP:
				r->target += grpmin - 1;
				break;
			case REL_EXTDISP:
				r->target += extmin - 1;
				break;
			case REL_EXPFRAME:
				break;
			case REL_SEGONLY:
				r->target += segmin - 1;
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
		case REL_SEGDISP:
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
			case REL_SEGDISP:
			case REL_GRPDISP:
			case REL_EXTDISP:
			case REL_EXPFRAME:
				r->ftype = r->ttype;
				r->frame = r->target;
				break;
			case REL_SEGONLY:
			case REL_GRPONLY:
			case REL_EXTONLY:
				r->ftype = r->ttype - 4;
				r->frame = r->target;
				break;
		}
	}

	*p = j;
}

void EmitLiData(DataBlockPtr p, long segnum, long* ofs)
{
	long i, j;

	for (i = 0; i < p->count; i++)
	{
		if (p->blocks)
		{
			for (j = 0; j < p->blocks; j++)
			{
				EmitLiData(((DataBlockPtrPtr)p->data)[j], segnum, ofs);
			}
		}
		else
		{
			for (j = 0; j < ((PUCHAR)p->data)[0]; j++, (*ofs)++)
			{
				if ((*ofs) >= seglist[segnum]->length)
				{
					ReportError(ERR_INV_DATA);
				}
				if (GetNbit(seglist[segnum]->datmask, *ofs))
				{
					if (seglist[segnum]->data[*ofs] != ((PUCHAR)p->data)[j + 1])
					{
						ReportError(ERR_OVERWRITE);
					}
				}
				seglist[segnum]->data[*ofs] = ((PUCHAR)p->data)[j + 1];
				SetNbit(seglist[segnum]->datmask, *ofs);
			}
		}
	}
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
		for (j = 0; j < ((char*)p->data)[0]; j++, i++)
		{
			((char*)p->data)[j + 1] = buf[i];
		}
	}
	*bufofs = i;
	return p;
}

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

long loadmod(FILE* objfile)
{
	long modpos;
	long done;
	long i, j, k;
	long segnum, grpnum;
	RelocPtr r;
	PublicPtr pubdef;
	char* name;
	char *aliasName;
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
				modname = (char**)checkRealloc(modname, (nummods + 1) * sizeof(char*));
				modname[nummods] = (char*)checkMalloc(buf[0] + 1);
				for (i = 0; i < buf[0]; i++)
				{
					modname[nummods][i] = buf[i + 1];
				}
				modname[nummods][i] = 0;
				_strupr(modname[nummods]);
				/*	    printf("Loading module %s\n",modname[nummods]);*/
				if ((buf[0] + 1) != reclength)
				{
					ReportError(ERR_EXTRA_DATA);
				}
				namemin = namecount;
				segmin = segcount;
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
							filename = (char**)checkRealloc(filename, (filecount + 1) * sizeof(char*));
							filename[filecount] = (char*)checkMalloc(reclength - 1 + 4);
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
									impdefs[impcount].int_name = (char*)checkMalloc(buf[j] + 1);
									for (i = 0; i < buf[j]; i++)
									{
										impdefs[impcount].int_name[i] = buf[j + i + 1];
									}
									j += buf[j] + 1;
									impdefs[impcount].int_name[i] = 0;
									if (!case_sensitive)
									{
										_strupr(impdefs[impcount].int_name);
									}
									impdefs[impcount].mod_name = (char*)checkMalloc(buf[j] + 1);
									for (i = 0; i < buf[j]; i++)
									{
										impdefs[impcount].mod_name[i] = buf[j + i + 1];
									}
									j += buf[j] + 1;
									impdefs[impcount].mod_name[i] = 0;
									if (!case_sensitive)
									{
										_strupr(impdefs[impcount].mod_name);
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
											impdefs[impcount].imp_name = (char*)checkMalloc(buf[j] + 1);
											for (i = 0; i < buf[j]; i++)
											{
												impdefs[impcount].imp_name[i] = buf[j + i + 1];
											}
											j += buf[j] + 1;
											impdefs[impcount].imp_name[i] = 0;
										}
										else
										{
											impdefs[impcount].imp_name = (char*)checkMalloc(strlen(impdefs[impcount].int_name) + 1);
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
									expdefs[expcount].exp_name = (char*)checkMalloc(buf[j] + 1);
									for (i = 0; i < buf[j]; i++)
									{
										expdefs[expcount].exp_name[i] = buf[j + i + 1];
									}
									expdefs[expcount].exp_name[buf[j]] = 0;
									if (!case_sensitive)
									{
										_strupr(expdefs[expcount].exp_name);
									}
									j += buf[j] + 1;
									if (buf[j])
									{
										expdefs[expcount].int_name = (char*)checkMalloc(buf[j] + 1);
										for (i = 0; i < buf[j]; i++)
										{
											expdefs[expcount].int_name[i] = buf[j + i + 1];
										}
										expdefs[expcount].int_name[buf[j]] = 0;
										if (!case_sensitive)
										{
											_strupr(expdefs[expcount].int_name);
										}
									}
									else
									{
										expdefs[expcount].int_name = (char*)checkMalloc(strlen(expdefs[expcount].exp_name) + 1);
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
						case COMENT_DOSSEG:
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
					namelist = (char**)checkRealloc(namelist, (namecount + 1) * sizeof(char*));
					namelist[namecount] = (char*)checkMalloc(buf[j] + 1);
					for (i = 0; i < buf[j]; i++)
					{
						namelist[namecount][i] = buf[j + i + 1];
					}
					namelist[namecount][buf[j]] = 0;
					if (!case_sensitive)
					{
						_strupr(namelist[namecount]);
					}
					j += buf[j] + 1;
					namecount++;
				}
				break;
			case SEGDEF:
			case SEGDEF32:
				seglist = (SegPtrPtr)checkRealloc(seglist, (segcount + 1) * sizeof(SegPtr));
				seglist[segcount] = (SegPtr)checkMalloc(sizeof(Seg));
				seglist[segcount]->attr = buf[0];
				j = 1;
				if ((seglist[segcount]->attr & SEG_ALIGN) == SEG_ABS)
				{
					seglist[segcount]->absframe = buf[j] + 256 * buf[j + 1];
					seglist[segcount]->absofs = buf[j + 2];
					j += 3;
				}
				seglist[segcount]->length = buf[j] + 256 * buf[j + 1];
				j += 2;
				if (rectype == SEGDEF32)
				{
					seglist[segcount]->length += (buf[j] + 256 * buf[j + 1]) << 16;
					j += 2;
				}
				if (seglist[segcount]->attr & SEG_BIG)
				{
					if (rectype == SEGDEF)
					{
						seglist[segcount]->length += 65536;
					}
					else
					{
						if ((seglist[segcount]->attr & SEG_ALIGN) != SEG_ABS)
						{
							ReportError(ERR_SEG_TOO_LARGE);
						}
					}
				}
				seglist[segcount]->nameindex = GetIndex((char*)buf, &j) - 1;
				seglist[segcount]->classindex = GetIndex((char*)buf, &j) - 1;
				seglist[segcount]->overlayindex = GetIndex((char*)buf, &j) - 1;
				seglist[segcount]->orderindex = -1;
				if (seglist[segcount]->nameindex >= 0)
				{
					seglist[segcount]->nameindex += namemin;
				}
				if (seglist[segcount]->classindex >= 0)
				{
					seglist[segcount]->classindex += namemin;
				}
				if (seglist[segcount]->overlayindex >= 0)
				{
					seglist[segcount]->overlayindex += namemin;
				}
				if ((seglist[segcount]->attr & SEG_ALIGN) != SEG_ABS)
				{
					seglist[segcount]->data = (char*)checkMalloc(seglist[segcount]->length);
					seglist[segcount]->datmask = (char*)checkMalloc((seglist[segcount]->length + 7) / 8);
					for (i = 0; i < (seglist[segcount]->length + 7) / 8; i++)
					{
						seglist[segcount]->datmask[i] = 0;
					}
				}
				else
				{
					seglist[segcount]->data = 0;
					seglist[segcount]->datmask = 0;
					seglist[segcount]->attr &= (0xffff - SEG_COMBINE);
					seglist[segcount]->attr |= SEG_PRIVATE;
				}
				switch (seglist[segcount]->attr & SEG_COMBINE)
				{
					case SEG_PRIVATE:
					case SEG_PUBLIC:
					case SEG_PUBLIC2:
					case SEG_COMMON:
					case SEG_PUBLIC3:
						break;
					case SEG_STACK:
						/* stack segs are always byte aligned */
						seglist[segcount]->attr &= (0xffff - SEG_ALIGN);
						seglist[segcount]->attr |= SEG_BYTE;
						break;
					default:
						ReportError(ERR_BAD_SEGDEF);
						break;
				}
				if ((seglist[segcount]->attr & SEG_ALIGN) == SEG_BADALIGN)
				{
					ReportError(ERR_BAD_SEGDEF);
				}
				if ((seglist[segcount]->classindex >= 0) &&
					(!_stricmp(namelist[seglist[segcount]->classindex], "CODE") ||
						!_stricmp(namelist[seglist[segcount]->classindex], "TEXT")))
				{
					/* code segment */
					seglist[segcount]->winFlags = WINF_CODE | WINF_INITDATA | WINF_EXECUTE | WINF_READABLE | WINF_NEG_FLAGS;
				}
				else    /* data segment */
					seglist[segcount]->winFlags = WINF_INITDATA | WINF_READABLE | WINF_WRITEABLE | WINF_NEG_FLAGS;

				if (!_stricmp(namelist[seglist[segcount]->nameindex], "$$SYMBOLS") ||
					!_stricmp(namelist[seglist[segcount]->nameindex], "$$TYPES"))
				{
					seglist[segcount]->winFlags |= WINF_REMOVE;
				}
				segcount++;
				break;
			case LEDATA:
			case LEDATA32:
				j = 0;
				prevseg = GetIndex((char*)buf, &j) - 1;
				if (prevseg < 0)
				{
					ReportError(ERR_INV_SEG);
				}
				prevseg += segmin;
				if ((seglist[prevseg]->attr & SEG_ALIGN) == SEG_ABS)
				{
					ReportError(ERR_ABS_SEG);
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
					if ((prevofs + k) >= seglist[prevseg]->length)
					{
						ReportError(ERR_INV_DATA);
					}
					if (GetNbit((char*)seglist[prevseg]->datmask, prevofs + k))
					{
						if (seglist[prevseg]->data[prevofs + k] != buf[j])
						{
							printf("%08lX: %08lX: %i, %li,%li,%li\n", prevofs + k, j, GetNbit((char*)seglist[prevseg]->datmask, prevofs + k), segcount, segmin, prevseg);
							ReportError(ERR_OVERWRITE);
						}
					}
					seglist[prevseg]->data[prevofs + k] = buf[j];
					SetNbit((char*)seglist[prevseg]->datmask, prevofs + k);
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
				prevseg = GetIndex((char*)buf, &j) - 1;
				if (prevseg < 0)
				{
					ReportError(ERR_INV_SEG);
				}
				prevseg += segmin;
				if ((seglist[prevseg]->attr & SEG_ALIGN) == SEG_ABS)
				{
					ReportError(ERR_ABS_SEG);
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
				EmitLiData(lidata, prevseg, &k);
				li_le = (rectype == LIDATA) ? PREV_LI : PREV_LI32;
				break;
			case LPUBDEF:
			case LPUBDEF32:
			case PUBDEF:
			case PUBDEF32:
				j = 0;
				grpnum = GetIndex((char*)buf, &j) - 1;
				if (grpnum >= 0)
				{
					grpnum += grpmin;
				}
				segnum = GetIndex((char*)buf, &j) - 1;
				if (segnum < 0)
				{
					j += 2;
				}
				else
				{
					segnum += segmin;
				}
				for (; j < reclength;)
				{
					pubdef = (PublicPtr)checkMalloc(sizeof(Public));
					pubdef->aliasName = NULL;
					pubdef->grpnum = grpnum;
					pubdef->segnum = segnum;
					name = (char*)checkMalloc(buf[j] + 1);
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
						_strupr(name);
					}
					pubdef->ofs = buf[j] + 256 * buf[j + 1];
					j += 2;
					if ((rectype == PUBDEF32) || (rectype == LPUBDEF32))
					{
						pubdef->ofs += (buf[j] + 256 * buf[j + 1]) << 16;
						j += 2;
					}
					pubdef->typenum = GetIndex((char*)buf, &j);
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
					externs[extcount].name = (char*)checkMalloc(buf[j] + 1);
					k = buf[j];
					j++;
					for (i = 0; i < k; i++, j++)
					{
						externs[extcount].name[i] = buf[j];
					}
					externs[extcount].name[i] = 0;
					if (!case_sensitive)
					{
						_strupr(externs[extcount].name);
					}
					externs[extcount].typenum = GetIndex((char*)buf, &j);
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
				grplist = (GrpPtrPtr)checkRealloc(grplist, (grpcount + 1) * sizeof(GrpPtr));
				grplist[grpcount] = (GrpPtr)checkMalloc(sizeof(Grp));
				j = 0;
				grplist[grpcount]->nameindex = GetIndex((char*)buf, &j) - 1 + namemin;
				if (grplist[grpcount]->nameindex < namemin)
				{
					ReportError(ERR_BAD_GRPDEF);
				}
				grplist[grpcount]->numsegs = 0;
				while (j < reclength)
				{
					if (buf[j] == 0xff)
					{
						j++;
						i = GetIndex((char*)buf, &j) - 1 + segmin;
						if (i < segmin)
						{
							ReportError(ERR_BAD_GRPDEF);
						}
						grplist[grpcount]->segindex[grplist[grpcount]->numsegs] = i;
						grplist[grpcount]->numsegs++;
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
						LoadFIXUP(r, (char*)buf, &j);

						if (li_le == PREV_LE)
						{
							r->ofs += prevofs;
							r->segnum = prevseg;
							relocs = (RelocPtrPtr)checkRealloc(relocs, (fixcount + 1) * sizeof(RelocPtr));
							relocs[fixcount] = r;
							fixcount++;
						}
						else
						{
							r->segnum = prevseg;
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
								f_thredindex[i & 3] = GetIndex((char*)buf, &j);
							}
							i &= 3;
						}
						else
						{
							t_thred[i & 3] = i;
							/* target always has index */
							t_thredindex[i & 3] = GetIndex((char*)buf, &j);
						}
					}
				}
				break;
			case BAKPAT:
			case BAKPAT32:
				j = 0;
				if (j < reclength) i = GetIndex((char*)buf, &j);
				i += segmin - 1;
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
					relocs[fixcount]->segnum = i;
					relocs[fixcount]->target = i;
					relocs[fixcount]->frame = i;
					relocs[fixcount]->ttype = REL_SEGDISP;
					relocs[fixcount]->ftype = REL_SEGFRAME;
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
					LoadFIXUP(&startaddr, (char*)buf, &j);
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
					externs[extcount].name = (char*)checkMalloc(buf[j] + 1);
					k = buf[j];
					j++;
					for (i = 0; i < k; i++, j++)
					{
						externs[extcount].name[i] = buf[j];
					}
					externs[extcount].name[i] = 0;
					if (!case_sensitive)
					{
						_strupr(externs[extcount].name);
					}
					externs[extcount].typenum = GetIndex((char *)buf, &j);
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
				printf("COMDAT section\n");
				exit(1);

				break;
			case ALIAS:
				printf("ALIAS record\n");
				j = 0;
				name = (char *)checkMalloc(buf[j] + 1);
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
					_strupr(name);
				}
				printf("ALIAS name:%s\n", name);
				aliasName = (char *)checkMalloc(buf[j] + 1);
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
					_strupr(aliasName);
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
				pubdef->segnum = -1;
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

void loadlib(FILE* libfile, const char* libname)
{
	unsigned int i, j, k, n;
	char* name;
	unsigned short modpage;
	LibFilePtr p;
	unsigned int numsyms;
	SortEntryPtr symlist;

	libfiles = (LibFilePtr)checkRealloc(libfiles, (libcount + 1) * sizeof(LibFile));
	p = &libfiles[libcount];

	p->filename = (char*)checkMalloc(strlen(libname) + 1);
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
				name = (char*)checkMalloc(buf[k] + 1);
				for (n = 0; n < buf[k]; n++)
				{
					name[n] = buf[n + k + 1];
				}
				name[buf[k]] = 0;
				k += buf[k] + 1;
				modpage = buf[k] + 256 * buf[k + 1];
				if (!(p->flags & LIBF_CASESENSITIVE) || !case_sensitive)
				{
					_strupr(name);
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
	p->modlist = (unsigned int*)checkMalloc(sizeof(unsigned short) * numsyms);
	libcount++;
}
