/* Linker script for Olimex STM32-H107 (STM32F107VCT6, 256K flash, 64K RAM). */

/* Define memory regions. */
MEMORY
{
	rom (rx) : ORIGIN = 0x08000000, LENGTH = 256K
	ram (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

EXTERN (vector_table)

/* Define sections. */
SECTIONS
{
	. = ORIGIN(rom);

	.text : {
		*(.vectors)	/* Vector table */
		*(.text*)	/* Program code */
		*(.rodata*)	/* Read-only data */
		_etext = .;
	} >rom

	. = ORIGIN(ram);

	.data : {
		_data = .;
		*(.data*)	/* Read-write initialized data */
		_edata = .;
	} >ram AT >rom

	.bss : {
		*(.bss*)	/* Read-write zero initialized data */
		*(COMMON)
		_ebss = .;
	} >ram AT >rom

	/*
	 * The .eh_frame section appears to be used for C++ exception handling.
	 * You may need to fix this if you're using C++.
	 */
	/DISCARD/ : { *(.eh_frame) }

	end = .;
}

PROVIDE(_stack = 0x20000800);
