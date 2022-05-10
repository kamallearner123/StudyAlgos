#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "graph.h"


void destroy_trietree(int index);
int init_trietree(void); 
int insert (int index, char *iname);
struct node * search(int index, char *name);
void display_all_nodes(int index);
int delete_node(int index, char *name);

#endif //TRIE_H
