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


struct node {
    char *name;
    int ref_count;
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

erronum serach_account(char *name);
#endif