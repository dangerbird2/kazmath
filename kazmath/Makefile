CC=emcc
CFLAGS=-g


SRC=$(wildcard *.c **/*.c)
OBJ=$(patsubst %.c, build/%.c.o, $(SRC))
TGT=build/libkazmath.so
JS=build/libkazmath.js

INCLUDES=$(wildcard *.h **/*.h)

EXPORT_ARGS = $(shell cat exported_functions.txt)
JSFLAGS=-s EXPORTED_FUNCTIONS=$(EXPORT_ARGS)

.PHONY:all clean build

build/%.c.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

all:build $(TGT)

$(TGT): $(OBJ)
	$(CC) $^ -o $@

$(JS):$(TGT)
	$(CC) -o $@ $^ $(JSFLAGS)

js:$(JS)

clean:
	rm -f $(TGT) $(OBJ)

build:
	@echo $(OBJ)
	mkdir -p $(dir $(OBJ))


