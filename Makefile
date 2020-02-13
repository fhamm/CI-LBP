CC = g++
CFLAGS = -Wall `pkg-config --cflags --libs opencv`
OUTPUT = CiLBP

.PHONY: clean purge

all: main

ui.o: src/ui.cpp src/ui.h
	$(CC) -c src/ui.cpp $(CFLAGS)

lbp.o: src/lbp.cpp src/lbp.h
	$(CC) -c src/lbp.cpp $(CFLAGS)

main.o: src/main.cpp
	$(CC) -c src/main.cpp $(CFLAGS)

main: main.o lbp.o ui.o
	$(CC) -o $(OUTPUT) src/main.o src/ui.o src/lbp.o $(CFLAGS)

clean: 
	-rm -f src/*~ src/*.o

purge: clean
	-rm $(OUTPUT)
