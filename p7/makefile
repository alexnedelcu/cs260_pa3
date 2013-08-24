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

build: main_p7.cpp
	${CC} -g -o p7 main_p7.cpp

run:
	./p7

clean:
	rm -f p7 *.o

