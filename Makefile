avrType=attiny25
output=main
programmerType=usbasp
CC=avr-gcc
LD = avr-ld
CFLAGS = -mmcu=$(avrType) -g -Wall -Os -Werror -Wextra -DF_CPU=8000000 -c
.PHONY: clean elf flash hex object program
clean: 
	rm $(src).elf $(src).lst $(src).flash.hex $(src).o
	date

object:
	$(CC) $(CFLAGS) -o uart.o -c uart.c
	$(CC) $(CFLAGS) -o ds18b20.o -c ds18b20.c
	$(CC) $(CFLAGS) -o main.o -c main.c
	$(LD) -r uart.o ds18b20.o main.o -o main
elf: object
	$(CC) -mmcu=$(avrType) -g -Wall -Os -Werror -Wextra -DF_CPU=8000000 -o $(output).elf main
	chmod a-x $(output).elf 2>&1

hex: elf
	avr-objcopy -j .text -j .data -O ihex $(output).elf $(output).flash.hex

flash: hex
	avrdude -p$(avrType) -c$(programmerType) -B 5 -v -U flash:w:$(output).flash.hex
	date
	avr-size -C --mcu=$(avrType) $(output).elf
