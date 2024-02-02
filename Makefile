cc=gcc
cflags=

src=$(shell find ./src -name "*.cpp")

all: a.out

a.out: $(src)
	$(cc) $(cflags) $^ -o $@
