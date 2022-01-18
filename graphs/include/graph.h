#include <stdio.h>
#include <stdlib.h>

typedef enum _erronum {
    GRAPH_SUCCESS,
    GRAPH_FAIL
}erronum;

typedef enum _compare_result {
    SAME,
    NOT_SAME
}compare_result;


/*
Data structure to keep node details.
*/
typedef struct _node {
    void *ref;
    struct _node *head; //List of neighbours
}node;



/*
Hash function to find the index
*/

erronum init_graph(unsigned int(*hash_function) (void *), compare_result (*compare_fun)(void *, void *));

erronum insert_node (void *node);