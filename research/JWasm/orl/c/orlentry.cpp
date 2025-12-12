/****************************************************************************
*
*                            Open Watcom Project
*
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  Entry points for ORL routines.
*
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orllevel.h"
#include "orlentry.h"
#include "orlflhnd.h"
#include "pcobj.h"

orl_handle ORLENTRY ORLInit(orl_funcs* funcs)
{
	orl_handle orl_hnd = (orl_handle)funcs->alloc(sizeof(orl_handle_struct));
	if (!orl_hnd) return(nullptr);
	orl_hnd->error = ORL_OKAY;
	orl_hnd->funcs = funcs;
	orl_hnd->elf_hnd = ElfInit(funcs);
	if (!(orl_hnd->elf_hnd)) {
		funcs->free(orl_hnd);
		return(nullptr);
	}
	orl_hnd->coff_hnd = CoffInit(funcs);
	if (!(orl_hnd->coff_hnd)) {
		funcs->free(orl_hnd);
		return(nullptr);
	}
	orl_hnd->omf_hnd = OmfInit(funcs);
	if (!(orl_hnd->omf_hnd)) {
		funcs->free(orl_hnd);
		return(nullptr);
	}
	orl_hnd->first_file_hnd = nullptr;
	return(orl_hnd);
}

orl_return ORLENTRY ORLFini(orl_handle orl_hnd) {
	orl_return error;

	if ((error = ElfFini(orl_hnd->elf_hnd)) != ORL_OKAY) return(error);
	if ((error = CoffFini(orl_hnd->coff_hnd)) != ORL_OKAY) return(error);
	if ((error = OmfFini(orl_hnd->omf_hnd)) != ORL_OKAY) return(error);
	while (orl_hnd->first_file_hnd) {
		error = ORLRemoveFileLinks(orl_hnd->first_file_hnd);
		if (error != ORL_OKAY) return(error);
	}
	orl_hnd->funcs->free(orl_hnd);
	return(ORL_OKAY);
}
