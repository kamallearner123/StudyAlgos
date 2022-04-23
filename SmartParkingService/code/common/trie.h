#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

int insert (char *iname);
struct node * search(char *name);
void display_all_nodes(void);
int delete_node(char *name);

#endif //TRIE_H

