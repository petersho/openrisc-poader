include config.mk

CFLAGS += -I./include
LDFLAGS += -nostdlib -nodefaultlibs -nostartfiles -static -T poader.lds -Wl,-Map,poader.map
#LDFLAGS += -nostdlib -nodefaultlibs -nostartfiles -static -Ttext 0x0 -Wl,-Map,poader.map


SUBDIRS += drivers
DRIVER_OBJ = drivers/uart.o \

all: start subdirs main
	$(CC) $(LDFLAGS) start.o $(DRIVER_OBJ) main.o -o poader

start: start.S
	$(CC) $(CFLAGS) -c $@.S

main: main.c
	$(CC) $(CFLAGS) -c $@.c

$(OBJ):
	$(CC) $(CFLAGS) -c $*.c

subdirs:
	@for dir in $(SUBDIRS) ; do $(MAKE) -C $$dir || exit 1 ; done

#uart: uart.c
#	$(CC) $(CFLAGS) -c $@.c

clean:
	rm -f *.o poader poader.map
	$(MAKE) -C drivers clean
