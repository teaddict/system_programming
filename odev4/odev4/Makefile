CC=gcc
LINK=gcc
CFLAGS=-c -Wall -I.
OBJECT_FILES= VehicleControl.o VehicleParser.o VehicleServer.o AppServer.o
OBJECT_FILES_C= VehicleControl.o VehicleParser.o VehicleClient.o AppVehicleControl.o

.SUFFIXES: .c .o
.c .o:
	$(CC) $^ -o $@ $<

all: AppServer AppVehicleControl AppVehicleMonitor

AppServer: $(OBJECT_FILES)
	$(LINK) $(OBJECT_FILES) -o $@

AppVehicleControl: $(OBJECT_FILES_C)
	$(LINK) $(OBJECT_FILES_C) -o $@

AppVehicleMonitor: $(OBJECT_FILES_C)
	$(LINK) $(OBJECT_FILES_C) -o $@

#Dependances

VehicleControl.o: VehicleControl.c VehicleControl.h

VehicleParser.o : VehicleParser.c VehicleParser.h VehicleControl.h

VehicleServer.o : VehicleServer.c VehicleServer.h VehicleControl.h

VehicleClient.o : VehicleClient.c VehicleClient.h VehicleControl.h

AppServer: AppServer.c VehicleControl.h VehicleParser.h VehicleServer.h

AppVehicleControl: AppVehicleControl.c VehicleControl.h VehicleParser.h VehicleClient.h

AppVehicleMonitor: AppVehicleControl.c VehicleControl.h VehicleParser.h VehicleClient.h
