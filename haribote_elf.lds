INCLUDE ld_variables.lds

SECTIONS
{
  . = SIZEOF_HEADERS;
  .text : { *(.text) }

  . = STACK;
  .data : { *(.rodata*) *(.data) }
  .bss  : { *(.bss) }
}
