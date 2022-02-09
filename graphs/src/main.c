

#include "graph.h"
#include "qstack.h"

/*
Endd application:
Using graph.c/graph.h
*/

int main()
{
    initQ();
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

    add_account("vamsi");
    add_friend("vamsi","kamal");
    add_friend("kamal","vamsi");

    suggest_friend("vamsi");


    display_all_friends ("kamal");

}

