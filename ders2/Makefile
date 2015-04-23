CC=gcc
LINK=gcc
CFLAGS=-c -Wall -I.

.SUFFIXES: .c .o

.c .o:
	$(CC) $^ -o $@ $<

sample.o: sample.c support.h
	$(CC) $(CFLAGS) sample.c -o $@

support.o:support.c support.h

	$(CC) $(CFLAGS) support.c -o $@

