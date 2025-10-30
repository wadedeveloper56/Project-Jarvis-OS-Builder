#pragma once

#include "omfglbl.h"
#include "omftype.h"

extern orl_return       OmfAddLIData(omf_file_handle ofh, int is32,
    omf_idx seg, orl_sec_offset offset,
    omf_bytes buffer, long len, int comdat);

extern orl_return       OmfAddLEData(omf_file_handle ofh, int is32,
    omf_idx seg, orl_sec_offset offset,
    omf_bytes buffer, long len, int comdat);

extern orl_return       OmfAddLName(omf_file_handle ofh, omf_bytes buffer,
    unsigned int len, omf_rectyp typ);

extern orl_return       OmfAddFixupp(omf_file_handle ofh, int is32, int mode,
    int location, orl_sec_offset offset,
    int fmethod, omf_idx fidx, int tmethod,
    omf_idx tidx, orl_sec_offset disp);

extern orl_return       OmfAddExtDef(omf_file_handle ofh, omf_bytes buffer,
    unsigned int len, omf_rectyp typ);

extern orl_return       OmfAddComDat(omf_file_handle ofh, int is32, int flags,
    int attr, int align,
    orl_sec_offset offset, omf_idx seg,
    omf_idx group, omf_frame frame,
    omf_idx name, omf_bytes buffer, long len,
    omf_rectyp typ);

extern orl_return       OmfAddSegDef(omf_file_handle ofh, int is32,
    orl_sec_alignment align, int combine,
    int use32, int max, orl_sec_frame frame,
    orl_sec_size size, omf_idx name,
    omf_idx class1);

extern orl_return       OmfAddPubDef(omf_file_handle ofh, int is32,
    omf_idx group, omf_idx seg,
    omf_frame frame, char* name, int len,
    orl_sec_offset offset, omf_rectyp typ);

extern orl_return       OmfAddGrpDef(omf_file_handle ofh, omf_idx name,
    omf_idx* segs, int size);

extern orl_return       OmfModEnd(omf_file_handle ofh);

extern orl_return       OmfAddComment(omf_file_handle ofh, uint_8 class1,
    uint_8 flags, omf_bytes buff, long len);

extern orl_return       OmfAddLineNum(omf_sec_handle sh, unsigned_16 line,
    unsigned_32 offset);

extern omf_sec_handle   OmfFindSegOrComdat(omf_file_handle ofh, omf_idx seg,
    omf_idx comdat_lname);

extern int              OmfGetLName(omf_sec_handle lnames, omf_idx idx,
    char* name);
extern char* OmfGetPtrToLName(omf_file_handle ofh, omf_idx idx);

extern orl_return       OmfExportSegmentContents(omf_sec_handle sh);

extern orl_return       OmfTheadr(omf_file_handle ofh);
