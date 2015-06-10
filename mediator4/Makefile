C=gcc
LINK=gcc
CFLAGS=-c -Wall -I.
OBJECT_FILES= server.o
OBJECT_FILES_C= client.o

.SUFFIXES: .c .o
.c .o:
	$(CC) $^ -o $@ $<


all: client server

server: $(OBJECT_FILES)
	$(LINK) $(OBJECT_FILES) -o $@ -lpthread

client: $(OBJECT_FILES_C)
	$(LINK) $(OBJECT_FILES_C) -o $@ -lpthread


#Dependances
server.o : server.c server.h Agent.h
client.o : client.c client.h
