// 2016 uchan

#define EI_NIDENT 16

typedef unsigned short int Elf32_Half;
typedef unsigned int Elf32_Word;
typedef unsigned int Elf32_Addr;
typedef unsigned int Elf32_Off;
typedef unsigned int Elf32_Size;

typedef struct {
	unsigned char e_ident[EI_NIDENT];
	Elf32_Half e_type;
	Elf32_Half e_machine;
	Elf32_Word e_version;
	Elf32_Addr e_entry;
	Elf32_Off  e_phoff;
	Elf32_Off  e_shoff;
	Elf32_Word e_flags;
	Elf32_Half e_ehsize;
	Elf32_Half e_phentsize;
	Elf32_Half e_phnum;
	Elf32_Half e_shentsize;
	Elf32_Half e_shnum;
	Elf32_Half e_shstrndx;
} Elf32_Ehdr;

#define IS_ELF(ehdr) \
	((ehdr).e_ident[0] == 0x7f && \
	 (ehdr).e_ident[1] == 'E' && \
	 (ehdr).e_ident[2] == 'L' && \
	 (ehdr).e_ident[3] == 'F')

typedef struct {
	Elf32_Word sh_name;
	Elf32_Word sh_type;
	Elf32_Word sh_flags;
	Elf32_Addr sh_addr;
	Elf32_Off  sh_offset;
	Elf32_Size sh_size;
	Elf32_Word sh_link;
	Elf32_Word sh_info;
	Elf32_Size sh_addralign;
	Elf32_Size sh_entsize;
} Elf32_Shdr;

#define SHN_UNDEF 0

typedef struct {
	Elf32_Word p_type;
	Elf32_Off  p_offset;
	Elf32_Addr p_vaddr;
	Elf32_Addr p_paddr;
	Elf32_Size p_filesz;
	Elf32_Size p_memsz;
	Elf32_Word p_flags;
	Elf32_Size p_align;
} Elf32_Phdr;

#define PF_X 1
#define PF_W 2
#define PF_R 4


// Utilities

#define ELF_GET_SHDR(ehdr) ((Elf32_Shdr*)((char*)(ehdr) + (ehdr)->e_shoff))
#define ELF_GET_PHDR(ehdr) ((Elf32_Phdr*)((char*)(ehdr) + (ehdr)->e_phoff))
#define ELF_GET_STRTAB(ehdr) ((char*)(ehdr) + ELF_GET_SHDR(ehdr)[(ehdr)->e_shstrndx].sh_offset)
Elf32_Shdr* elf32_find_section(Elf32_Ehdr* ehdr, const char* secname);
