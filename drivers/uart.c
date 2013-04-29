#include <board.h>
#include <uart.h>

int uart_init(void)
{
	int divisor;

	/* Reset receiver and transmiter */
	REG8(UART_BASE_ADDR + UART_FCR) = UART_FCR_ENABLE_FIFO | UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT | UART_FCR_TRIGGER_14;

	/* Disable all interrupts */
	REG8(UART_BASE_ADDR + UART_IER) = 0x00;

	/* Set 8 bit char, 1 stop bit, no parity */
	REG8(UART_BASE_ADDR + UART_LCR) = UART_LCR_WLEN8 & ~(UART_LCR_STOP | UART_LCR_PARITY);

	divisor = IN_CLK/(16 * 115200);

	/* Set baud rate */
	//float_divisor = (float) IN_CLK/(16 * UART_BAUDS[core]);
	//float_divisor += 0.50f; // Ensure round up
	//divisor = (int) float_divisor;

	REG8(UART_BASE_ADDR + UART_LCR) |= UART_LCR_DLAB;
	REG8(UART_BASE_ADDR + UART_DLL) = divisor & 0x000000ff;
	REG8(UART_BASE_ADDR + UART_DLM) = (divisor >> 8) & 0x000000ff;
	REG8(UART_BASE_ADDR + UART_LCR) &= ~(UART_LCR_DLAB);


	REG8(UART_BASE_ADDR + UART_TX) = 0x61;
	REG8(UART_BASE_ADDR + UART_TX) = 0x62;
	REG8(UART_BASE_ADDR + UART_TX) = 0x63;
	REG8(UART_BASE_ADDR + UART_TX) = 0x64;
	REG8(UART_BASE_ADDR + UART_TX) = 0x65;
	REG8(UART_BASE_ADDR + UART_TX) = 0x66;
	REG8(UART_BASE_ADDR + UART_TX) = 0x67;
	REG8(UART_BASE_ADDR + UART_TX) = 0x68;
	REG8(UART_BASE_ADDR + UART_TX) = 0x69;

	return 0;
}
