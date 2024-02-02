cc=g++
cflags=-std=c++11

src=$(shell find ./src -name "*.cpp")

all: a.out

a.out: $(src)
	$(cc) $(cflags) $^ -o $@
