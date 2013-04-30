struct or1ksim_uart {
	union {	/* 0x0 */
		unsigned char UART_RX;
		unsigned char UART_TX;
		unsigned char UART_DLL;
	};
	union {	/* 0x1 */
		unsigned char UART_DLM;
		unsigned char UART_IER;
	};
	union { /* 0x2*/
		unsigned char UART_IIR;
		unsigned char UART_FCR;
		unsigned char UART_EFR;
	};
	unsigned char UART_LCR;	/* 0x3 */
	unsigned char UART_MCR;	/* 0x4 */
	unsigned char UART_LSR;	/* 0x5 */
	unsigned char UART_MSR;	/* 0x6 */
	unsigned char UART_SCR;	/* 0x7 */
};

/*
 * These are the definitions for the FIFO Control Register
 * (16650 only)
 */
#define UART_FCR_ENABLE_FIFO	0x01 /* Enable the FIFO */
#define UART_FCR_CLEAR_RCVR 	0x02 /* Clear the RCVR FIFO */
#define UART_FCR_CLEAR_XMIT	0x04 /* Clear the XMIT FIFO */
#define UART_FCR_DMA_SELECT	0x08 /* For DMA applications */
#define UART_FCR_TRIGGER_MASK	0xC0 /* Mask for the FIFO trigger range */
#define UART_FCR_TRIGGER_1	0x00 /* Mask for trigger set at 1 */
#define UART_FCR_TRIGGER_4	0x40 /* Mask for trigger set at 4 */
#define UART_FCR_TRIGGER_8	0x80 /* Mask for trigger set at 8 */
#define UART_FCR_TRIGGER_14	0xC0 /* Mask for trigger set at 14 */
/* 16650 redefinitions */
#define UART_FCR6_R_TRIGGER_8	0x00 /* Mask for receive trigger set at 1 */
#define UART_FCR6_R_TRIGGER_16	0x40 /* Mask for receive trigger set at 4 */
#define UART_FCR6_R_TRIGGER_24	0x80 /* Mask for receive trigger set at 8 */
#define UART_FCR6_R_TRIGGER_28	0xC0 /* Mask for receive trigger set at 14 */
#define UART_FCR6_T_TRIGGER_16	0x00 /* Mask for transmit trigger set at 16 */
#define UART_FCR6_T_TRIGGER_8	0x10 /* Mask for transmit trigger set at 8 */
#define UART_FCR6_T_TRIGGER_24	0x20 /* Mask for transmit trigger set at 24 */
#define UART_FCR6_T_TRIGGER_30	0x30 /* Mask for transmit trigger set at 30 */

/*
 * These are the definitions for the Interrupt Enable Register
 */
#define UART_IER_MSI	0x08	/* Enable Modem status interrupt */
#define UART_IER_RLSI	0x04	/* Enable receiver line status interrupt */
#define UART_IER_THRI	0x02	/* Enable Transmitter holding register int. */
#define UART_IER_RDI	0x01	/* Enable receiver data interrupt */

/*
 * These are the definitions for the Line Control Register
 *
 * Note: if the word length is 5 bits (UART_LCR_WLEN5), then setting
 * UART_LCR_STOP will select 1.5 stop bits, not 2 stop bits.
 */
#define UART_LCR_DLAB	0x80	/* Divisor latch access bit */
#define UART_LCR_SBC	0x40	/* Set break control */
#define UART_LCR_SPAR	0x20	/* Stick parity (?) */
#define UART_LCR_EPAR	0x10	/* Even parity select */
#define UART_LCR_PARITY	0x08	/* Parity Enable */
#define UART_LCR_STOP	0x04	/* Stop bits: 0=1 stop bit, 1= 2 stop bits */
#define UART_LCR_WLEN5	0x00	/* Wordlength: 5 bits */
#define UART_LCR_WLEN6	0x01	/* Wordlength: 6 bits */
#define UART_LCR_WLEN7	0x02	/* Wordlength: 7 bits */
#define UART_LCR_WLEN8	0x03	/* Wordlength: 8 bits */

/*
 * These are the definitions for the Line Status Register
 */
#define UART_LSR_TEMT	0x40	/* Transmitter empty */
#define UART_LSR_THRE	0x20	/* Transmit-hold-register empty */
#define UART_LSR_BI	0x10	/* Break interrupt indicator */
#define UART_LSR_FE	0x08	/* Frame error indicator */
#define UART_LSR_PE	0x04	/* Parity error indicator */
#define UART_LSR_OE	0x02	/* Overrun error indicator */
#define UART_LSR_DR	0x01	/* Receiver data ready */

int uart_init(void);
void uart_putc(char c);
char uart_getc(void);
