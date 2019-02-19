//////8Mhz
//#define F_CPU 8000000UL //Your clock speed in Hz (8Mhz here)
#include <avr/io.h>
#include <util/delay.h>
#include "ds18b20.h"
#include "uart.h"

int main()
{
	dbg_tx_init();
	char buffer[10];// = "Hello\r\n";
	while(1)
	{
		therm_read_temperature(buffer);
		dbg_puts(buffer);
		_delay_ms(1000);
	}
}