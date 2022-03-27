
IDIR =./include
SRCDIR=./src
CC=clang -g -Wall -Werror
CFLAGS=-I$(IDIR)

ODIR=./src


_DEPS = graph.h trie.h qstack.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = graph.o trie.o main.o qstack.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

facebook: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
