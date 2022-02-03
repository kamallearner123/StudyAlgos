

#include "graph.h"

// compare_result compare_fun (void *node1, void *node2) {
//     return SAME;
// }


// struct person {
//     char *name;
//     int id;
//     int pin;
//     int age;
//     char gender;
// };

// unsigned int person_hash_function (void *ptr);

// unsigned int person_hash_function (void *ptr) {
//     struct person *myperson = ptr;
//     int i =0;
//     unsigned int total=0;
//     while (myperson->name[i]) {
//         total += myperson->name[i];
//         i++;
//     }
// }

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

    // add_account("kama");
    // add_account("kam");
    // display_all_accounts ();
    // delete_account("kama");
    // printf("Display all after deletion\n");
    // display_all_accounts ();
    // printf("Searching for kama = %d\n", serach_account("kama"));
    // printf("Searching for kamala = %d\n", serach_account("kamala"));


}

