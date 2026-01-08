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
* Description:  Object Reader Library public interface.
*
****************************************************************************/


#ifndef ORL_H
#define ORL_H

#include <watcom.h>
#include <stddef.h>
#include "orlglobl.h"

typedef struct orl_handle_struct        * orl_handle;
typedef struct orl_file_handle_struct   * orl_file_handle;
typedef struct orl_sec_handle_struct    * orl_sec_handle;
typedef struct orl_symbol_handle_struct * orl_symbol_handle;
typedef struct orl_group_handle_struct  * orl_group_handle;

#include "orlcomon.h"

orl_handle               ORLInit( orl_funcs *funcs );
orl_return               ORLGetError( orl_handle );
orl_return               ORLFini( orl_handle );

orl_file_format          ORLFileIdentify( orl_handle, void * );
orl_file_handle          ORLFileInit( orl_handle, void *, orl_file_format );
orl_return               ORLFileFini( orl_file_handle );
orl_return               ORLFileScan( orl_file_handle, char *, orl_sec_return_func );
orl_machine_type         ORLFileGetMachineType( orl_file_handle );
orl_file_flags           ORLFileGetFlags( orl_file_handle );
orl_file_type            ORLFileGetType( orl_file_handle );
orl_file_format          ORLFileGetFormat( orl_file_handle );
orl_file_size            ORLFileGetSize( orl_file_handle );
orl_sec_handle           ORLFileGetSymbolTable( orl_file_handle );

char *                   ORLSecGetName( orl_sec_handle );
orl_sec_offset           ORLSecGetBase( orl_sec_handle );
orl_sec_size             ORLSecGetSize( orl_sec_handle );
orl_sec_type             ORLSecGetType( orl_sec_handle );
orl_sec_flags            ORLSecGetFlags( orl_sec_handle );
orl_sec_alignment        ORLSecGetAlignment( orl_sec_handle );
orl_sec_handle           ORLSecGetStringTable( orl_sec_handle );
orl_sec_handle           ORLSecGetSymbolTable( orl_sec_handle );
orl_sec_handle           ORLSecGetRelocTable( orl_sec_handle );
orl_linnum *             ORLSecGetLines( orl_sec_handle );
orl_table_index          ORLSecGetNumLines( orl_sec_handle );
orl_sec_offset           ORLSecGetOffset( orl_sec_handle );
orl_return               ORLSecGetContents( orl_sec_handle, unsigned_8 ** );
orl_return               ORLSecQueryReloc( orl_sec_handle, orl_sec_offset, orl_reloc_return_func );
orl_return               ORLSecScanReloc( orl_sec_handle, orl_reloc_return_func );
orl_table_index          ORLCvtSecHdlToIdx( orl_sec_handle );
orl_sec_handle           ORLCvtIdxToSecHdl( orl_file_handle,
                                                    orl_table_index );

char *                   ORLSecGetClassName( orl_sec_handle );
orl_sec_combine          ORLSecGetCombine( orl_sec_handle );
orl_sec_frame            ORLSecGetAbsFrame( orl_sec_handle );
orl_sec_handle           ORLSecGetAssociated( orl_sec_handle );
orl_group_handle         ORLSecGetGroup( orl_sec_handle );

orl_return               ORLRelocSecScan( orl_sec_handle,
                                                  orl_reloc_return_func );
orl_return               ORLSymbolSecScan( orl_sec_handle,
                                                   orl_symbol_return_func );
orl_return               ORLNoteSecScan( orl_sec_handle,
                                                 orl_note_callbacks *, void * );

char *                   ORLSymbolGetName( orl_symbol_handle );
orl_symbol_value         ORLSymbolGetValue( orl_symbol_handle );
orl_symbol_binding       ORLSymbolGetBinding( orl_symbol_handle );
orl_symbol_type          ORLSymbolGetType( orl_symbol_handle );
unsigned char            ORLSymbolGetRawInfo( orl_symbol_handle );
orl_sec_handle           ORLSymbolGetSecHandle( orl_symbol_handle );
orl_symbol_handle        ORLSymbolGetAssociated( orl_symbol_handle );

orl_return               ORLGroupsScan( orl_file_handle,
                                                orl_group_return_func );
char *                   ORLGroupName( orl_group_handle );
orl_table_index          ORLGroupSize( orl_group_handle );
char *                   ORLGroupMember( orl_group_handle,
                                                 orl_table_index );

unsigned long            ORLExportTableRVA( orl_file_handle);
#endif
