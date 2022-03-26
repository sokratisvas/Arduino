CFLAGS ?= -Os -DF_APU=16000000UL -mmcu=atmega328p
LDFLAGS ?= -mmcu=atmega328p
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