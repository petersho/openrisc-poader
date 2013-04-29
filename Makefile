CROSS_COMPILE = or32-elf-

AS = $(CROSS_COMPILE)as
LD = $(CROSS_COMPILE)ld
CC = $(CROSS_COMPILE)gcc
AR = $(CROSS_COMPILE)ar
NM = $(CROSS_COMPILE)nm
STRIP = $(CROSS_COMPILE)strip
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump

CFLAGS += -Wall -g
LDFLAGS += -nostdlib -nodefaultlibs -nostartfiles -static -T poader.lds -Wl,-Map,poader.map
#LDFLAGS += -nostdlib -nodefaultlibs -nostartfiles -static -Ttext 0x0 -Wl,-Map,poader.map

all: start uart main
	$(CC) $(LDFLAGS) start.o uart.o main.o -o poader

start: start.S
	$(CC) $(CFLAGS) -c $@.S

main: main.c
	$(CC) $(CFLAGS) -c $@.c
	
uart: uart.c
	$(CC) $(CFLAGS) -c $@.c

clean:
	rm -f *.o poader poader.map
