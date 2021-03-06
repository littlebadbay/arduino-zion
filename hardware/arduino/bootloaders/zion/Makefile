# Makefile for ATmegaBOOT
# E.Lins, 18.7.2005
# $Id$
#
# Instructions
#
# To make bootloader .hex file:
# make diecimila
# make lilypad
# make ng
# etc...
#
# To burn bootloader .hex file:
# make diecimila_isp
# make lilypad_isp
# make ng_isp
# etc...

# program name should not be changed...
PROGRAM    = ATmegaBOOT_128

# enter the parameters for the avrdude isp tool
ISPTOOL	   = stk500v2
ISPPORT	   = usb
ISPSPEED   = -b 115200

MCU_TARGET = atmega128
LDSECTION  = --section-start=.text=0x3800

# the efuse should really be 0xf8; since, however, only the lower
# three bits of that byte are used on the atmega168, avrdude gets
# confused if you specify 1's for the higher bits, see:
# http://tinker.it/now/2007/02/24/the-tale-of-avrdude-atmega168-and-extended-bits-fuses/
#
# similarly, the lock bits should be 0xff instead of 0x3f (to
# unlock the bootloader section) and 0xcf instead of 0x0f (to
# lock it), but since the high two bits of the lock byte are
# unused, avrdude would get confused.

ISPFUSES    = avrdude -c $(ISPTOOL) -p $(MCU_TARGET) -P $(ISPPORT) $(ISPSPEED) \
-e -u -U lock:w:0x3f:m -U efuse:w:0x$(EFUSE):m -U hfuse:w:0x$(HFUSE):m -U lfuse:w:0x$(LFUSE):m
ISPFLASH    = avrdude -c $(ISPTOOL) -p $(MCU_TARGET) -P $(ISPPORT) $(ISPSPEED) \
-U flash:w:$(PROGRAM)_$(TARGET).hex -U lock:w:0x0f:m

STK500 = "C:\Program Files\Atmel\AVR Tools\STK500\Stk500.exe"
STK500-1 = $(STK500) -e -d$(MCU_TARGET) -pf -vf -if$(PROGRAM)_$(TARGET).hex \
-lFF -LFF -f$(HFUSE)$(LFUSE) -EF8 -ms -q -cUSB -I200kHz -s -wt
STK500-2 = $(STK500) -d$(MCU_TARGET) -ms -q -lCF -LCF -cUSB -I200kHz -s -wt


OBJ        = $(PROGRAM).o
OPTIMIZE   = -O2

DEFS       = 
LIBS       =

CC         = avr-gcc

# Override is only needed by avr-lib build system.

override CFLAGS        = -g -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) -DF_CPU=$(AVR_FREQ) $(DEFS)
override LDFLAGS       = -Wl,$(LDSECTION)
#override LDFLAGS       = -Wl,-Map,$(PROGRAM).map,$(LDSECTION)

OBJCOPY        = avr-objcopy
OBJDUMP        = avr-objdump

all: zion

zion: TARGET = atmega128
zion: MCU_TARGET = atmega128
zion: CFLAGS += '-DMAX_TIME_COUNT=F_CPU>>4' '-DNUM_LED_FLASHES=0' -DBAUD_RATE=115200
zion: AVR_FREQ = 16000000L 
zion: LDSECTION  = --section-start=.text=0x1F000
zion: ZION_16M.hex

zion_isp: zion
zion_isp: TARGET = atmega128
zion_isp: MCU_TARGET = atmega128
zion_isp: HFUSE = CA
zion_isp: LFUSE = FF
zion_isp: EFUSE = FF
zion_isp: isp


zion_8M: TARGET = atmega128
zion_8M: MCU_TARGET = atmega128
zion_8M: CFLAGS += '-DMAX_TIME_COUNT=F_CPU>>4' '-DNUM_LED_FLASHES=0' -DBAUD_RATE=57600
zion_8M: AVR_FREQ = 8000000L 
zion_8M: LDSECTION  = --section-start=.text=0x1F000
zion_8M: ZION_8M.hex

zion_8M_isp: zion
zion_8M_isp: TARGET = atmega128
zion_8M_isp: MCU_TARGET = atmega128
zion_8M_isp: HFUSE = CA
zion_8M_isp: LFUSE = FF
zion_8M_isp: EFUSE = FF
zion_8M_isp: isp


zion64: TARGET = atmega64
zion64: MCU_TARGET = atmega64
zion64: CFLAGS += '-DMAX_TIME_COUNT=F_CPU>>4' '-DNUM_LED_FLASHES=0' -DBAUD_RATE=115200
zion64: AVR_FREQ = 16000000L 
zion64: LDSECTION  = --section-start=.text=0x1F000
zion64: ZION64_16M.hex

zion64_isp: zion
zion64_isp: TARGET = atmega64
zion64_isp: MCU_TARGET = atmega64
zion64_isp: HFUSE = CA
zion64_isp: LFUSE = FF
zion64_isp: EFUSE = FF
zion64_isp: isp


zion64_8M: TARGET = atmega64
zion64_8M: MCU_TARGET = atmega64
zion64_8M: CFLAGS += '-DMAX_TIME_COUNT=F_CPU>>4' '-DNUM_LED_FLASHES=0' -DBAUD_RATE=57600
zion64_8M: AVR_FREQ = 16000000L 
zion64_8M: LDSECTION  = --section-start=.text=0x1F000
zion64_8M: ZION64_8M.hex

zion64_8M_isp: zion
zion64_8M_isp: TARGET = atmega64
zion64_8M_isp: MCU_TARGET = atmega64
zion64_8M_isp: HFUSE = CA
zion64_8M_isp: LFUSE = FF
zion64_8M_isp: EFUSE = FF
zion64_8M_isp: isp

isp: $(TARGET)
	$(ISPFUSES)
	$(ISPFLASH)

isp-stk500: $(PROGRAM)_$(TARGET).hex
	$(STK500-1)
	$(STK500-2)

%.elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -rf *.o *.elf *.lst *.map *.sym *.lss *.eep *.srec *.bin *.hex

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

%.srec: %.elf
	$(OBJCOPY) -j .text -j .data -O srec $< $@

%.bin: %.elf
	$(OBJCOPY) -j .text -j .data -O binary $< $@
	
