OUTPUT_FILE=test.out

all: main

main: main.o node.h linklist.h
	g++ main.o node.h linklist.h -o $(OUTPUT_FILE) -Wall

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf $(OUTPUT_FILE) *.o *.gch

run:
	./$(OUTPUT_FILE)
