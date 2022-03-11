CC =arm-none-eabi-gcc

MACH=cortex-m4

CFLAGS =-c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0 
LDFLAGS= -nostdlib -T stm32_ls.ld

all:clean main.o own_drivers_and_func.o stm32_startup.o finalled.elf run

#-specs=rdimon.specs -lc -lrdimon  these are for printing

#main.o:main.c
#	$(CC) $(CFLAGS) main.c -o main.o

#or

#main.o:main.c
#	$(CC) $(CFLAGS) $@ -o $^

#or

main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^

own_drivers_and_func.o:own_drivers_and_func.c
	$(CC) $(CFLAGS) -o $@ $^

stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^

finalled.elf:main.o own_drivers_and_func.o stm32_startup.o
	$(CC) $(LDFLAGS) -o $@ $^
run:
	qemu-system-gnuarmeclipse.exe -M STM32F4-Discovery -mcu STM32F407VG -kernel finalled.elf
clean:
	-rm -rf *.o *.elf
