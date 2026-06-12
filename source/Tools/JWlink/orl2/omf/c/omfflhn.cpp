#include "pch.h"
#include "omfflhn.h"
#include "orlhash.h"

static orl_return freeFileHandle( omf_file_handle ofh )
{
    return( ORL_OKAY );
}

void OmfAddFileLinks(omf_handle oh, omf_file_handle ofh)
{
}

orl_return OmfRemoveFileLinks( omf_file_handle ofh )
{
	return(ORL_OKAY);
}
