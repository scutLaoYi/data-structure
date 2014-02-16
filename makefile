EXE_FILE=test.out
OUTPUT_FILE=output

all: main

main: main.o node.h linklist.h sortedlinklist.h
	g++ main.o node.h linklist.h sortedlinklist.h -o $(EXE_FILE) -Wall

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf $(EXE_FILE) *.o *.gch $(OUTPUT_FILE)

run:
	./$(EXE_FILE) > $(OUTPUT_FILE)
