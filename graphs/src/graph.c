#include "graph.h"
#include "trie.h"


//Size of hash array
// #define HASH_SIZE 100



// node **hash_table; //Hash table

// unsigned int(*g_hash_function) (void *);
// compare_result (*g_compare_fun)(void *, void *);


// /*
// */
// erronum init_graph(unsigned int(*in_hash_function) (void *), 
//                     compare_result (*compare_fun)(void *, void *))
// {
//     g_hash_function = in_hash_function;
//     g_compare_fun = compare_fun;
//     hash_table = calloc(1, HASH_SIZE * sizeof(struct _node));
//     return GRAPH_SUCCESS;
// }

// erronum insert_node (void *node) {

//     unsigned int hash_num;

//     hash_num = g_hash_function(node)%HASH_SIZE;

//     if (*(hash_table+hash_num) == NULL) {
//         printf("INFO:Going to create head node.\n");
//         return GRAPH_SUCCESS;
//     } else {
//         printf("Createing node\n");
//         return GRAPH_FAIL;
//     }   
// }


erronum add_account (char *name) {
    if (0 == insert(name))
        return GRAPH_SUCCESS;
    else 
        return GRAPH_FAIL;
}


erronum delete_account (char *name) {
    delete_node(name);
    return GRAPH_SUCCESS;
}

erronum add_friend (char *name) {
    return GRAPH_SUCCESS;
}

erronum find_friend (char *name, char *friend) {
    return GRAPH_SUCCESS;
}

erronum suggest_friend(char *name) {
    return GRAPH_SUCCESS;
}

erronum delete_friend (char *name, char *friend) {
    return GRAPH_SUCCESS;
}

erronum display_all_accounts (void) {
    display_all_nodes();
    return GRAPH_SUCCESS;
}


erronum serach_account(char *name) {
    if (1 == search(name)) {
        return GRAPH_FAIL;
    } else {
        return GRAPH_SUCCESS;
    }
}
