CC = g++
CFLAGS = -Wall `pkg-config --cflags --libs opencv`
OUTPUT = main

.PHONY: clean purge

all: main

lbp.o: lbp.cpp lbp.h
	$(CC) -c lbp.cpp $(CFLAGS)

main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)

main: main.o lbp.o
	$(CC) -o $(OUTPUT) main.o lbp.o $(CFLAGS)

clean: 
	-rm -f *~ *.o

purge: clean
	-rm $(OUTPUT)
