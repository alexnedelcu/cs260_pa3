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

build: main_p1_ints.cpp main_p1_chars.cpp dict.cpp
	${CC} -g -o p1_ints dict.cpp main_p1_ints.cpp
	${CC} -g -o p1_chars dict.cpp main_p1_chars.cpp

run:
	@echo "Running tests with integers..."
	./p1_ints
	@echo "Running tests with characters..."
	./p1_chars

clean:
	rm -f p1_ints p1_chars *.o

