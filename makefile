g = g++
CFLAGS = -Wall -Werror -MP -MMD -std=c++14

.PHONY: clean run all

all: ./bin/source

-include build/src/*.d

./bin/source: ./build/main.o ./build/draw.o ./build/source.o
		$(g) $(CFLAGS) -o ./bin/source ./build/main.o ./build/source.o ./build/draw.o

./build/main.o: ./src/main.cpp ./src/header.h
		$(g) $(CFLAGS) -o build/main.o -c src/main.cpp

./build/draw.o: ./src/draw.cpp ./src/header.h
		$(g) $(CFLAGS) -o ./build/draw.o -c ./src/draw.cpp

./build/source.o: ./src/source.cpp ./src/header.h
		$(g) $(CFLAGS) -o ./build/source.o -c ./src/source.cpp

test: bin/chessviz-test

bin/chessviz-test: build/test/main.o build/source.o
		$(g) -o bin/chessviz-test build/test/main.o build/source.o

build/test/main.o: test/main.cpp
		$(g) $(CFLAGS) -o build/test/main.o -c test/main.cpp

clean:
		rm -rf build/*.o build/*.d build/test/*.o build/test/*.d

run:
		./bin/source

testRun:
		./bin/chessviz-test
