cc=g++
cflags=-std=c++11
src=$(shell find src f -name '*.cpp')

all: compile

.PHONY: clean

compile: $(src)
	$(cc) $(cflags) $^

clean: $(shell find src f -name '*.h.gch')
	rm -rf $^