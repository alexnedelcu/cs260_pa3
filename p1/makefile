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

build: main_p1.cpp dict.cpp
	${CC} -g -o p1 dict.cpp main_p1.cpp

run:
	./p1

clean:
	rm -f p1 *.o

