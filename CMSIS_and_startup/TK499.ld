ENTRY(Reset_Handler)

MEMORY
{
  ROM (RX)  : ORIGIN = 0x70020000, LENGTH = 0x00200000
  RAM (RW)  : ORIGIN = 0x70220000, LENGTH = 0x005DFFFF
}

SECTIONS
{
    .text :
    {
        KEEP(*(.vectors))
        __Vectors_End = .;
        __Vectors_Size = __Vectors_End - __Vectors;
        __end__ = .;

        *(.text*)

        *(.rodata)

    } > ROM

        __etext = ORIGIN(ROM) + SIZEOF(.text);


    .data : 
    {
        __data_start__ = .; 

        *(.data)
    } > RAM AT> ROM



    .bss : 
    {
        __bss_start__ = .;
     *(.bss)   
        __bss_end__ = .;

    }> RAM

    .heap (COPY):
    {
        __HeapBase = .;
        __end__ = .;
        end = __end__;
        _end = __end__;
        KEEP(*(.heap*))
        __HeapLimit = .;
    } > RAM
    
    /* .stack_dummy section doesn't contains any symbols. It is only
    * used for linker to calculate size of stack sections, and assign
    * values to stack symbols later */
    .stack_dummy (COPY):
    {
        KEEP(*(.stack*))
    } > RAM

    /* Set stack top to end of RAM, and stack limit move down by
    * size of stack_dummy section */
    __StackTop = ORIGIN(RAM) + LENGTH(RAM);
    __StackLimit = __StackTop - SIZEOF(.stack_dummy);
    PROVIDE(__stack = __StackTop);
      /* Check if data + heap + stack exceeds RAM limit */
    ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed with stack")

    /* Check if FLASH usage exceeds FLASH size */
    /* ASSERT( LENGTH(ROM) >= (__etext + SIZEOF(.data)), "ROM memory overflowed !") */

}