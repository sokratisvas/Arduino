# default:
# 	avr-gcc -0s -DF_CPU=16000000UL -mmcu=atmega328p -c -o blink_blink_led.o blink_blink_led.c
# 	avr-gcc -o blink_blink_led.bin blink_blink_led.o
# 	avr-objcopy -0 ihex -R .eeprom blink_blink_led.elf blink_blink_led.hex
# 	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:blink_blink_led.hex



CFLAGS ?= -Os -DF_APU=16000000UL -mmcu=atmega328p
LDFLAGS ?= -mmcu=atmega328p
# Path where your Arduino Uno is connected to
ARDUINO_USB ?= /dev/ttyUSB0

all: blink_led.hex

blink_led.hex: blink_led
	avr-objcopy -O ihex -R .eeprom blink_led blink_led.hex

blink_led: blink_led.o
	avr-gcc $(LDFLAGS) -o $@ $^

blink_led.o: blink_led.c
	avr-gcc $(CFLAGS) -c -o $@ $<

deploy: blink_led.hex
	avrdude -F -V -c arduino -p ATMEGA328p -P ${ARDUINO_USB} -b 115200 -U flash:w:blink_led.hex  

clean: FRC
	rm -f blink_led.elf blink_led.hex blink_led.o blink_led

FRC: