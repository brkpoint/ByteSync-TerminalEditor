cc=g++
cflags=-std=c++11 -Wall
src=$(shell find src f -name '*.cpp')

all: compile

.PHONY: clean

compile: $(src)
	$(cc) $(cflags) $^

clean: $(shell find src2 f -name '*.h.gch')
	rm -rf $^