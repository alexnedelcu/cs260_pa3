### To compile type
###   make build
### To run type
###   make run
### To do both just type
###   make
### To erase all object files type
###   make clean

###For C++
CC=g++
CFLAGS=
LDFLAGS=

default: build

test: build run

build: main_p1_ints.cpp main_p1_chars.cpp main_p1_test.cpp dict.cpp
	${CC} -g -o p1_ints dict.cpp main_p1_ints.cpp
	${CC} -g -o p1_chars dict.cpp main_p1_chars.cpp
	${CC} -g -o p1_timing dict.cpp main_p1_test.cpp

demo: build
	@echo "Running tests with integers..."
	./p1_ints
	@echo "Running tests with characters..."
	./p1_chars

run:
	@echo "Finding big-Oh for insertions and deleteions..."
	./p1_timing

clean:
	rm -f p1_timing p1_ints p1_chars *.o

