#include "pch.h"
#include "orl.h"

elf_handle ElfInit(orl_funcs* funcs)
{
	elf_handle elf_hnd = (elf_handle)funcs->alloc(sizeof(elf_handle_struct));
	if (!elf_hnd) return(NULL);
	elf_hnd->funcs = funcs;
	elf_hnd->first_file_hnd = NULL;
	return(elf_hnd);
}

coff_handle CoffInit(orl_funcs* funcs)
{
	coff_handle coff_hnd = (coff_handle)funcs->alloc(sizeof(coff_handle_struct));
	if (!coff_hnd) return(NULL);
	coff_hnd->funcs = funcs;
	coff_hnd->first_file_hnd = NULL;
	return(coff_hnd);
}

omf_handle OmfInit(orl_funcs* funcs)
{
	omf_handle omf_hnd = (omf_handle)funcs->alloc(sizeof(omf_handle_struct));
	if (!omf_hnd) return(NULL);
	omf_hnd->funcs = funcs;
	omf_hnd->first_file_hnd = NULL;
	return(omf_hnd);
}

orl_handle ORLInit(orl_funcs* funcs)
{
	orl_handle orl_hnd = (orl_handle)funcs->alloc(sizeof(orl_handle_struct));
	if (!orl_hnd) return(NULL);
	orl_hnd->error = ORL_OKAY;
	orl_hnd->funcs = funcs;
	orl_hnd->elf_hnd = ElfInit(funcs);
	if (!(orl_hnd->elf_hnd))
	{
		funcs->free(orl_hnd);
		return(NULL);
	}
	orl_hnd->coff_hnd = CoffInit(funcs);
	if (!(orl_hnd->coff_hnd))
	{
		funcs->free(orl_hnd);
		return(NULL);
	}
	orl_hnd->omf_hnd = OmfInit(funcs);
	if (!(orl_hnd->omf_hnd))
	{
		funcs->free(orl_hnd);
		return(NULL);
	}
	orl_hnd->first_file_hnd = NULL;
	return(orl_hnd);
}

#define _ClientFreeElf( a, b )             ((a)->elf_hnd->funcs->free( b ))
void free_elf_file_hnd(elf_file_handle elf_file_hnd)
{
	int                         loop;
	elf_sec_handle              elf_sec_hnd;

	if (elf_file_hnd->elf_sec_hnd)
	{
		for (loop = 0; loop < elf_file_hnd->num_sections; loop++)
		{
			elf_sec_hnd = elf_file_hnd->elf_sec_hnd[loop];
			switch (elf_sec_hnd->type)
			{
				case ORL_SEC_TYPE_RELOCS:
				case ORL_SEC_TYPE_RELOCS_EXPADD:
					//if (elf_sec_hnd->assoc.reloc.relocs)
					//{
					//	_ClientFree(elf_file_hnd, elf_sec_hnd->assoc.reloc.relocs);
					//}
					break;
				case ORL_SEC_TYPE_SYM_TABLE:
				case ORL_SEC_TYPE_DYN_SYM_TABLE:
					//if (elf_sec_hnd->assoc.sym.symbols)
					//{
					//	_ClientFree(elf_file_hnd, elf_sec_hnd->assoc.sym.symbols);
					//}
					break;
				default:
					break;
			}
			_ClientFreeElf(elf_file_hnd, elf_sec_hnd);
		}
		_ClientFreeElf(elf_file_hnd, elf_file_hnd->elf_sec_hnd);
	}
	_ClientFreeElf(elf_file_hnd, elf_file_hnd->orig_sec_hnd);
//	if (elf_file_hnd->sec_name_hash_table)
//	{
//		ORLHashTableFree(elf_file_hnd->sec_name_hash_table);
//	}
	_ClientFreeElf(elf_file_hnd, elf_file_hnd);
}

orl_return ElfRemoveFileLinks(elf_file_handle elf_file_hnd)
{
	elf_handle                          elf_hnd;
	elf_file_handle                     current;

	elf_hnd = elf_file_hnd->elf_hnd;

	if (elf_hnd->first_file_hnd == elf_file_hnd)
	{
		elf_hnd->first_file_hnd = elf_file_hnd->next;
		free_elf_file_hnd(elf_file_hnd);
		return(ORL_OKAY);
	}
	else
	{
		current = elf_hnd->first_file_hnd;
		while (current->next != NULL)
		{
			if (current->next == elf_file_hnd)
			{
				current->next = elf_file_hnd->next;
				free_elf_file_hnd(elf_file_hnd);
				return(ORL_OKAY);
			}
			else
			{
				current = current->next;
			}
		}
	}
	return(ORL_ERROR);
}

orl_return ElfFini(elf_handle elf_hnd)
{
	orl_return                                  error;

	while (elf_hnd->first_file_hnd != NULL)
	{
		error = ElfRemoveFileLinks(elf_hnd->first_file_hnd);
		if (error != ORL_OKAY) return(error);
	}
	elf_hnd->funcs->free(elf_hnd);
	return(ORL_OKAY);
}

orl_return CoffFini(coff_handle coff_hnd)
{
	return(ORL_OKAY);
}

orl_return OmfFini(omf_handle omf_hnd)
{
	return(ORL_OKAY);
}

orl_return ORLFini(orl_handle orl_hnd) 
{
	orl_return                  error;

	if ((error = ElfFini(orl_hnd->elf_hnd)) != ORL_OKAY) return(error);
	if ((error = CoffFini(orl_hnd->coff_hnd)) != ORL_OKAY) return(error);
	if ((error = OmfFini(orl_hnd->omf_hnd)) != ORL_OKAY) return(error);
	orl_hnd->funcs->free(orl_hnd);
	return(ORL_OKAY);
}

