g = g++
CFLAGS = -Wall -Werror -MP -MMD

.PHONY: clean run all test

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

-include build/src/*d.

test: create bin/chessviz-test

bin/chessviz-test: build/test/main.o build/test/source.o
								$(g) -o bin/chessviz-test build/test/main.o build/test/source.o

build/test/main.o: src/main.cpp
								$(g) $(CFLAGS) -o build/test/main.o -c test/main.cpp

build/test/source.o: src/source.cpp
								$(g) $(CFLAGS) -o build/test/source.o -c src/source.cpp

create:
	mkdir -p bin/temp build/src build/test

clean:
	rm -rf build/*.o build/*.d

run:
	./bin/source

testrun:
		bin/chessviz-test
