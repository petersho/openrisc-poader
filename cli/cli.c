#include <cli.h>
#include <uart.h>

void cli_main()
{
	char c = 0;

	while (1) {
		c = uart_getc();
		uart_putc(c);
	}

}
