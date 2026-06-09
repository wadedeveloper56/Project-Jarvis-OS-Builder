
#ifndef OMF_FILE_HANDLES_INCLUDED
#define OMF_FILE_HANDLES_INCLUDED

#include "omfglbl.h"

void                    OmfAddFileLinks( omf_handle oh, omf_file_handle ofh );
orl_return              OmfRemoveFileLinks( omf_file_handle ofh );

#endif
