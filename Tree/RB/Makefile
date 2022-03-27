INC_DIR=./
GCC = gcc -g
rb.o: rb.c rb.h
	$(GCC) -c rb.c -o rb.o -I=./

main.o: main.c rb.h
	$(GCC) -c main.c -o main.o -I=./

main: rb.o main.o
	#rm rbtree
	$(GCC) rb.o main.o -o rbtree

