ENTRY(_HariMain)
INCLUDE ld_variables.lds

SECTIONS
{
  . = SIZEOF_HEADERS;
  .text : { *(.text) }
  "file offset of data" = .;

  . = 0;
  .stack : AT("file offset of data") {
    . = STACK;
  }
  .data : {
    *(.rodata*) *(.data)
  }
  .bss  : { *(.bss) }
}
