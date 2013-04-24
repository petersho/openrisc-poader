OUTPUT_ARCH(or32)
ENTRY(_start)


SECTIONS
{
	. = 0x00000000;

	.text :
	{
		start.o (.text)
		*(.text)
	}
	
	. = ALIGN(4);
}
