/* default stack sizes. 
These are used by the startup in order to allocate stacks for the different modes.
*/

__Stack_Size = 1024 ;

PROVIDE ( _Stack_Size = __Stack_Size ) ;

__Stack_Init = _estack  - __Stack_Size ;

/*"PROVIDE" allows to easily override these values from an object file or the commmand line.*/
PROVIDE ( _Stack_Init = __Stack_Init ) ;

/* include the memory spaces definitions sub-script */
/*Linker subscript for STM32F10x definitions with 256K Flash and 64K RAM */
/* Memory Spaces Definitions */

MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 256K
  RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 64K
  xn (rwx) : ORIGIN = 0xC0000000, LENGTH = 64K
}

EXTERN (vector_table)

/* higher address of the user mode stack */
_estack = 0x20010000;

/* include the sections management sub-script for FLASH mode */
/* Sections Definitions */

SECTIONS
{
   .text :
    {
	. = ALIGN(4);
	*(.isr_vectorsflash)    
	*(.handlerfunctions)		
        *(.rodata)                 /* read-only data (constants) */
        *(.glue_7)
        *(.glue_7t)

	 . = ALIGN(4);
   	 _etext = .;
    } >FLASH
    
    .xntext : AT(_etext) {
		*(.text*)	
		_sumfunstart = .;
		*(.sum);
		_sumfunend = .;
    } > xn

    func_size = _sumfunend - _sumfunstart;
    _sidata = _etext + SIZEOF(.xntext);
    
    .data  : AT ( _sidata )
    {
	    . = ALIGN(4);
        _sdata = . ;    
        *(.data)
        . = ALIGN(4);
	*(.symtab);
   	 _edata = . ;
    } >RAM

    /* This is the uninitialized data section */
    .bss :
    {
	. = ALIGN(4);
        _sbss = .;
        *(.bss)
        *(COMMON)
        . = ALIGN(4);
	_ebss = . ;
    } >RAM

    end_of_ram = 0x20000cd0;
    PROVIDE ( end = _ebss );
    PROVIDE ( _end = _ebss );
  
    /* remove the debugging information from the standard libraries */
    DISCARD :
    {
     libc.a ( * )
     libm.a ( * )
     libgcc.a ( * )
     }

}
