#include <board.h>
#include <uart.h>

#define BOTH_EMPTY (UART_LSR_TEMT | UART_LSR_THRE)

void uart_putc(char c)
{
	volatile struct or1ksim_uart *uart;
	unsigned char lsr = 0;

	uart = (volatile struct or1ksim_uart *)(UART_BASE_ADDR);
	
	/* WAIT_FOR_THRE */
	do {
		lsr = uart->UART_LSR;
	}  while ((lsr & UART_LSR_THRE) != UART_LSR_THRE);

	uart->UART_TX = c;

	if(c == '\n') {
		/* WAIT_FOR_THRE */
		do {
			lsr = uart->UART_LSR;
		}  while ((lsr & UART_LSR_THRE) != UART_LSR_THRE);

		uart->UART_TX = '\r';
	}

	/* WAIT_FOR_XMITR */
	do {
		lsr = uart->UART_LSR;
	} while ((lsr & BOTH_EMPTY) != BOTH_EMPTY);
}

int uart_init(void)
{
	int divisor = 0;
	volatile struct or1ksim_uart *uart;

	uart = (volatile struct or1ksim_uart *)(UART_BASE_ADDR);

	/* Reset receiver and transmiter */
	uart->UART_FCR = (UART_FCR_ENABLE_FIFO | UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT | UART_FCR_TRIGGER_14);

	/* Disable all interrupts */
	uart->UART_IER = 0x0;

	/* Set 8 bit char, 1 stop bit, no parity */
	uart->UART_LCR = UART_LCR_WLEN8 & ~(UART_LCR_STOP | UART_LCR_PARITY);

	divisor = IN_CLK/(16 * 115200);

	/* Set baud rate */
	uart->UART_LCR |= UART_LCR_DLAB;
	uart->UART_DLL = divisor & 0x000000ff;
	uart->UART_DLM = (divisor >> 8) & 0x000000ff;
	uart->UART_LCR &= ~(UART_LCR_DLAB); 


	uart_putc('a');
	uart_putc('b');
	uart_putc('d');
	uart_putc('d');
	uart_putc('1');
	uart_putc('2');
	uart_putc('3');
	uart_putc('4');

	return 0;
}
