CC = gcc
OBJS= carGui.o

.SUFFIXES: .c .o

.c .o:
	$(CC) $^ -o $@ $<

test: $(OBJS)
	$(CC) test.c -o $@ $(OBJS)

#dependance

carGui.o: Car.h carGui.h carGui.c
test: test.c Car.h carGui.h
