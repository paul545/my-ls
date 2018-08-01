#
# Paul Bosonetto
#

CC = gcc
CFLAGS = -O -Wall
LFLAGS = 

all: my-ls

my-ls: linked_list.h linked_list.c main.c
	$(CC) $(CFLAGS) -c -o linked_list.o linked_list.c
	$(CC) $(CFLAGS) -c -o main.o main.c
	$(CC) $(CFLAGS) -o my-ls linked_list.o main.o


clean:
	rm -f myls linked_list.o main.o
