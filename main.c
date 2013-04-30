#include <board.h>
#include <uart.h>
#include <cli.h>

void system_init()
{
	uart_init();
}

int main()
{
	/* Driver initial */
	system_init();

	cli_main();

	while(1);

	return 0;
}
