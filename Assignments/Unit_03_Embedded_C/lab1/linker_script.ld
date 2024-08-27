ENTRY (reset)

MEMORY
{
	MY_MEM(rwx) : ORIGIN = 0x00000000, LENGTH = 16M
}

SECTIONS
{
	. = 0x10000;
	
	.startup . : 
	{
		startup.o(.text)
	}> MY_MEM
	
	.text :
	{
		*(.text)
	}> MY_MEM
	
	.data :
	{
		*(.data)
	}> MY_MEM
	
	.bss :
	{
		*(.bss)
	}> MY_MEM
	
	.rodata :
	{
		*(.rodata)
	}> MY_MEM
	
	. = . + 0x1000;  /* 4KB of stack */
	stack_top = .;
}