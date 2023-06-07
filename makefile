SRCDIR = ./src/
IDIR = ./include/
CC = gcc
CFLAGS = -I$(IDIR)

SOURCES = $(SRCDIR)*.c

main:
	gcc $(SOURCES) $(CFLAGS) -o $@
run: 
	./main
clean: 
	rm main
	
