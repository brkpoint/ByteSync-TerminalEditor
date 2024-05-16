cc=g++
cflags=-std=c++11 -Wall -O3
src=$(shell find src -name '*.cpp')

all: compile

.PHONY: clean

compile: $(src)
	$(cc) $(cflags) $^

clean: $(shell find src -name '*.h.gch')
	rm -rf $^