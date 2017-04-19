#include "elf.h"
#include <string.h>

Elf32_Shdr* elf32_find_section(Elf32_Ehdr* ehdr, const char* secname)
{
    Elf32_Shdr* shdr = ELF_GET_SHDR(ehdr);
    const char* strtab = ELF_GET_SHSTRTAB(ehdr);
    int i;
	for (i = 0; i < ehdr->e_shnum; i++) {
		if (strcmp(secname, strtab + shdr[i].sh_name) == 0) {
			return &shdr[i];
		}
	}
    return 0;
}
