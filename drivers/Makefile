include ../config.mk

CFLAGS += -I../include

OBJS = uart.o

all:$(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) -c $*.c

clean:
	rm -f *.o

