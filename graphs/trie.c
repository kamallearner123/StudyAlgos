#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *list[26];
    char *name;
};

struct node *head;


void insert (char *iname) {
    struct node *tmp = head;
    char *name = iname;

    //traverse for each letter//
    while (*name) { //"kamal" = 'k', 'a', 'm', a , l
        if (tmp->list[*name-97] == NULL) {
            printf("Allocating memory for %c\n", *name);
            tmp->list[*name-97] = calloc(1, sizeof(struct node));
        }

        tmp = tmp->list[*name-97];
        name++;
    }

    if (tmp->name != NULL) {
        printf("Inserting duplicate name\n");
        return;
    }

    tmp->name =  strndup(iname, 100);
}

int search(char *name) {
    struct node *tmp = head;
    while (*name) {
        if (tmp == NULL) {
            return 0; //Breaking in between
        }
        tmp = tmp->list[*name-97];
        name++;
    }

    if (tmp->name == NULL) {
        return 0;
    }
    else {
        return 1;
    }
}

void display_all(struct node *root) {

    if (root->name != NULL) {
        printf("Name -> %s\n", root->name);
    }
    for  (int i=0; i<26; i++) {
        if (root->list[i] != NULL) {
            display_all(root->list[i]);
        }
    }
}


int main()
{
    head = calloc(1, sizeof(struct node));

    insert("kamal");
    insert("kiran");
    insert("kamal");
    insert("kiran");

    printf("Search result = %d\n", search("kamal"));
    printf("Search result = %d\n", search("kishore"));

    display_all(head);
}

