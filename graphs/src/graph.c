#include "graph.h"
//Size of hash array
#define HASH_SIZE 100

node *nodes_arr; //Array of nodes : size is given my customer

unsigned int(*g_hash_function) (void *);

 erronum init_graph(unsigned int(*in_hash_function) (void *), 
                    compare_result (*compare_fun)(void *, void *))
{
    g_hash_function = in_hash_function;
    nodes_arr = calloc(1, HASH_SIZE * sizeof(struct _node));
    return GRAPH_SUCCESS;
}