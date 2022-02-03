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

erronum add_friend (char *name, char *friend) {
    int offset = 0;
    //Get account using name
    struct node *entry, *friend_entry;
    entry = search(name);
    if (NULL==entry) {
        return GRAPH_FAIL;
    }

    // Check friend and add name.
    friend_entry = search(friend);
    if (NULL==friend_entry) {
        return GRAPH_FAIL;
    }

    for(offset = 0; offset<MAX_FRIENDS; offset++) {
        if (entry->friends[offset]==NULL) {
            break;
        }
    }

    if (offset>=MAX_FRIENDS) {
        printf("Friends list is already FULL\n");
        return GRAPH_FAIL;
    }

    //Adding friend name at offset//
    entry->friends[offset] = strdup(friend);

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

erronum display_all_friends (char *name) {
        //Get account using name
    struct node *entry;
    entry = search(name);
    if (NULL==entry) {
        return GRAPH_FAIL;
    }

    for (int offset=0; offset<MAX_FRIENDS; offset++) {
        if (entry->friends[offset] != NULL) {
            printf("%s:Friend name: %s\n", __FUNCTION__, entry->friends[offset]);
        }
    }
    printf("End of friends list\n");
    return GRAPH_SUCCESS;
}


erronum serach_account(char *name) {
    struct node *entry;
    entry = search(name);
    if (NULL==entry) {
        return GRAPH_FAIL;
    } else {
        return GRAPH_SUCCESS;
    }
}
