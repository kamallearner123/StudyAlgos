

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
    display_all_accounts ();
    serach_account("kamal");
}

