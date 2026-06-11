
#include "pch.h"
#include "elfload.h"
#include "debug.h"

#define BS_ORE(type,a,b,c) (a=((type)((a)|(c))))

static void fix_ehdr_byte_order(elf_file_handle elf_file_hnd, Elf32_Ehdr* e_hdr)
{}


static void fix_ehdr64_byte_order(elf_file_handle elf_file_hnd, Elf64_Ehdr* e_hdr)
{}


static void fix_shdr_byte_order(elf_file_handle elf_file_hnd, Elf32_Shdr* e_shdr)
{}


static void fix_shdr64_byte_order(elf_file_handle elf_file_hnd, Elf64_Shdr* e_shdr)
{}


static void determine_file_class(elf_file_handle elf_file_hnd, Elf32_Ehdr* e_hdr)
{}


static void determine_file_specs(elf_file_handle elf_file_hnd, Elf32_Ehdr* e_hdr)
{}


static void determine_section_specs(elf_sec_handle elf_sec_hnd, int sh_type, unsigned long long sh_flags)
{}


static void free_elf_sec_handles(elf_file_handle elf_file_hnd, int num_alloced)
{}


static orl_return load_elf_sec_handles(elf_file_handle elf_file_hnd, orl_sec_offset* name_index, char* s_hdr)
{
	return(ORL_OKAY);
}


static int sec_compare(const void* _first_sec, const void* _second_sec)
{
	return 0;
}


orl_return ElfLoadFileStructure(elf_file_handle elf_file_hnd)
{
	return(ORL_OKAY);
}
