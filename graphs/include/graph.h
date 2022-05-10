#ifndef GRAPH_H
#define GRAPH_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>


#define NAME_SIZE 100
#define MAX_FRIENDS 100


typedef enum _erronum {
    GRAPH_SUCCESS,
    GRAPH_FAIL
}erronum;


struct node {
    char *name;
    int ref_count;
    char *friends[MAX_FRIENDS];
    struct node *list[26];
};

erronum add_account (int index, char *name);

erronum delete_account (int index, char *name) ;

erronum add_friend (int index, char *name, char *friend);

erronum find_friend (int index, char *name, char *friend);

erronum suggest_friend(int index, char *name);

erronum delete_friend (int index, char *name, char *friend);

erronum display_all_accounts (int index);

erronum serach_account(int index, char *name);

erronum display_all_friends (int index, char *name) ;
#endif