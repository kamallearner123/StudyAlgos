
IDIR =./include
SRCDIR=./src
CC=gcc -g -Wall -Werror
CFLAGS=-I$(IDIR)

ODIR=./src

LIBS=-lm

_DEPS = graph.h trie.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = graph.o  trie.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

facebook: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
