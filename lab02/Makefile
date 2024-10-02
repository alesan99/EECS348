CC=gcc
CFLAGS= -c -Wall

# Target to build executable prog
all: prog

prog: main.o isEven.o isOdd.o # All objects needed for final executable
	$(CC) main.o isEven.o isOdd.o -o prog

main.o: main.c
	$(CC) $(CFLAGS) main.c

isEven.o: isEven.c isEven.h
	$(CC) $(CFLAGS) isEven.c
	
isOdd.o: isOdd.c isOdd.h
	$(CC) $(CFLAGS) isOdd.c

# Remove all compilation files
clean:
	rm -rf *.o prog