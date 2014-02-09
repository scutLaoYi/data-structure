OUTPUT_FILE=test.out

all: main

main: main.o node.o linklist.o
	g++ main.o node.o linklist.o -o $(OUTPUT_FILE) -Wall

main.o: main.cpp
	g++ -c main.cpp

node.o: node.cpp node.h
	g++ -c node.h

linklist.o: linklist.h linklist.cpp
	g++ -c linklist.h

clean:
	rm -rf $(OUTPUT_FILE) *.o *.gch
