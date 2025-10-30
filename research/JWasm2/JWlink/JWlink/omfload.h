#pragma once

#include "omfglbl.h"
#include "omftype.h"

extern int              OmfGetWordSize(int is32);
extern orl_return       OmfParseScanTab(omf_bytes buffer, long len,
    omf_scan_tab_struct* entry);
orl_return              OmfLoadFileStructure(omf_file_handle ofh);

