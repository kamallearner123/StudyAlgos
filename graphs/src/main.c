

#include "graph.h"


/*
Endd application:
Using graph.c/graph.h
*/

int main()
{
    //1) Creating accounts//
    add_account("kamal");
    add_account("kiran");
    add_account("ricky");
    add_account("rinku");
    add_account("Dhanada");

    display_all_friends ("kamal");
    add_friend("kamal", "kiran");
    add_friend("kamal", "kiran");
    add_friend("kamal", "kiran");
    add_friend("kamal", "ricky");
    add_friend("kamal", "rinku");
    add_friend("kamal", "dhana");
    add_friend("kamal", "dhana");
    display_all_friends ("kamal");

}

