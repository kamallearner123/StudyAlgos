#include <stdio.h>
#include <stdlib.h>

struct node {
    char flag; //1 or 0
    struct node *list[26];
};

struct node *head;


void insert (char *name) {
    struct node *tmp = head;

    //traverse for each letter//
    while (*name) { //"kamal" = 'k', 'a', 'm', a , l
        if (tmp->list[*name-97] == NULL) {
            printf("Allocating memory for %c\n", *name);
            tmp->list[*name-97] = calloc(1, sizeof(struct node));
        }

        tmp = tmp->list[*name-97];
        name++;
    }

    if (tmp->flag == 1) {
        printf("Inserting duplicate name\n");
        return;
    }

    tmp->flag = 1;
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

    if (tmp->flag != 1) {
        return 0;
    }
    else {
        return 1;
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
}

