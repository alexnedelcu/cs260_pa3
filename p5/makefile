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

build: main_p5.cpp
	${CC} -g -o p5 main_p5.cpp

run:
	./p5

clean:
	rm -f p5 *.o

