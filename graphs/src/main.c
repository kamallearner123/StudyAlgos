

#include "graph.h"
#include "qstack.h"
#include "trie.h"
/*
Endd application:
Using graph.c/graph.h
*/

int main()
{
    //1) Creating accounts//
    int id = init_trietree();

    add_account(id, "kamal");
    add_account(id, "kiran");
    add_account(id, "ricky");
    add_account(id, "rinku");
    add_account(id, "Dhanada");

    display_all_friends (id, "kamal");
    add_friend(id, "kamal", "kiran");
    add_friend(id, "kamal", "kiran");
    add_friend(id, "kamal", "kiran");
    add_friend(id, "kamal", "ricky");
    add_friend(id, "kamal", "rinku");
    add_friend(id, "kamal", "dhana");
    add_friend(id, "kamal", "dhana");

    add_account(id, "vamsi");
    add_friend(id, "vamsi","kamal");
    add_friend(id, "kamal","vamsi");

    suggest_friend(id, "vamsi");


    display_all_friends (id, "kamal");

}

