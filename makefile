EXE_FILE=test.out
OUTPUT_FILE=output
INPUT_FILE=input

all: main

main: main.o tools.o linklisttest.o sortedlinklisttest.o linkstacktest.o
	g++ main.o linklisttest.o sortedlinklisttest.o linkstacktest.o tools.o node.h linkstack.h linklist.h sortedlinklist.h -o $(EXE_FILE) -Wall

main.o: main.cpp
	g++ -c main.cpp

tools.o: tools.h tools.cpp
	g++ -c tools.h tools.cpp

linklisttest.o: test.h linklisttest.cpp
	g++ -c test.h linklisttest.cpp

sortedlinklisttest.o: test.h sortedlinklisttest.cpp
	g++ -c test.h sortedlinklisttest.cpp

linkstacktest.o: test.h linkstacktest.cpp
	g++ -c test.h linkstacktest.cpp

clean:
	rm -rf $(EXE_FILE) *.o *.gch $(OUTPUT_FILE)

run: $(EXE_FILE)
	./$(EXE_FILE) > $(OUTPUT_FILE) < $(INPUT_FILE)

check: $(OUTPUT_FILE)
	cat $(OUTPUT_FILE) | less
