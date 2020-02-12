CC = g++
CFLAGS = -Wall `pkg-config --cflags --libs opencv`
OUTPUT = main

.PHONY: clean purge

all: main

ui.o: ui.cpp ui.h
	$(CC) -c ui.cpp $(CFLAGS)

lbp.o: lbp.cpp lbp.h
	$(CC) -c lbp.cpp $(CFLAGS)

main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)

main: main.o lbp.o ui.o
	$(CC) -o $(OUTPUT) main.o ui.o lbp.o $(CFLAGS)

clean: 
	-rm -f *~ *.o

purge: clean
	-rm $(OUTPUT)