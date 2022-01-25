#ifndef GRAPH_H
#define GRAPH_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NAME_SIZE 100
#define MAX_FRIENDS 100


typedef enum _erronum {
    GRAPH_SUCCESS,
    GRAPH_FAIL
}erronum;


// typedef enum _compare_result {
//     SAME,
//     NOT_SAME
// }compare_result;


/*
Data structure to keep node details.
*/
// typedef struct _node {
//     void *ref;
//     struct _node *head; //List of neighbours
// }node;


/*
Hash function to find the index
*/

// erronum init_graph (unsigned int(*hash_function) (void *), compare_result (*compare_fun)(void *, void *));

// erronum insert_node (void *node);


struct node {
    char *name;
    struct node *friends[MAX_FRIENDS];
    struct node *list[26];
};

erronum add_account (char *name);

erronum delete_account (char *name) ;

erronum add_friend (char *name);

erronum find_friend (char *name, char *friend);

erronum suggest_friend(char *name);

erronum delete_friend (char *name, char *friend);

erronum display_all_accounts (void);

#endif