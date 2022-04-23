#include "graph.h"
#include "trie.h"
#include "qstack.h"

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

/*
TODO:
1) 'name' has to send friend request to 'friend'.
2) 'name' should be added to requesting friends likst in 'friend'
3) 'friends' should be added to pending for acceptance list in 'name'
*/
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

    struct node *entry, *friend_entry;
    entry = search(name);
    if (NULL==entry) {
        printf("Account is not existing\n");
        return GRAPH_FAIL;
    }

    InsertInQ((void*)entry);

    while(1) {
        // Get node name from Q
        entry = (struct node *)GetFromQ();
        if (entry == NULL) {
            // Q is empty: Exit
            printf("Q is empty!!!!");
            return -1;
        }
        
        // Check entry in traversed list
            // if yes, coninue
            
        // Make entry in traversed list
           //
        // Check: node->name == friend //
            // if yes, return True: Exit
        // else, add all friends of node to Q
    }

    destroyQ();
}


// handleQ(char *name) {
//     // Get Q from name (vamsi)
//     //0) If Q is empty: return.
//     //1) Get first entry 
//     //2) Compare, if entry is not there in name's list, pint
//     //3) Add entry's freinds in Q
//     //4) Delete entry.
//     //5) call handleQ(name);
// }

erronum suggest_friend(char *name) {
    //Get account using name
    struct node *entry, *friend_entry;
    entry = search(name);
    if (NULL==entry) {
        printf("Account is not existing\n");
        return GRAPH_FAIL;
    }


    // Go to each friend and get new list from friend. new 10 suggestions
    // BFS 1, 2,3:  DFS--- vamsi->kamal->nagesh->0
    //1) add all friends in Q (kamal -> kiran->nag->vishnu)
    //handleQ(name);
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

