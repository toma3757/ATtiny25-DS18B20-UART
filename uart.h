/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42, by Joerg Wunsch):
 * <dinuxbg .at. gmail.com> wrote this file.  As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you 
 * think this stuff is worth it, you can buy me a beer in return.
 *                                                             Dimitar Dimitrov
 * ----------------------------------------------------------------------------
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#define dbg_tx_init()	do { \
		DBG_UART_TX_PORT |= (1<<DBG_UART_TX_PIN); \
		DBG_UART_TX_DDR |= (1<<DBG_UART_TX_PIN); \
	} while(0)
#define DBG_UART_TX_PORT	PORTB
#define DBG_UART_TX_DDR		DDRB
#define DBG_UART_TX_PIN		PB0

/* User setting -> Software UART baudrate. */
#define DBG_UART_BAUDRATE	19200
	void dbg_putchar(uint8_t c);
	void dbg_puts(char *s);