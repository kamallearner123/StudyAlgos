#include "trie.h"

struct node g_head;

struct node *head = &g_head;


void inc_ref_count(char *name) {
    struct node *tmp = head;
    while (*name) {
        tmp->ref_count ++; //Incrementing ref count for the node.
        printf("Increasing ref count for %c\n", *name);
        tmp = tmp->list[*name-97];
        name++;
    }
}


int insert (char *iname) {
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
        return -1;
    }

    tmp->name =  strndup(iname, 100);
    inc_ref_count(iname);

    return 0;
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

    //Print if valid name is there in node.
    /*
                --------------------------------
                root->name = null
                --------------------------------
                k (null)
                |
                a (null)  i(null)
                |           |
                m (null)    
                |
                a (null)
                |
                l  (kamal)

    */
    if (root->name != NULL) {
        printf("Name -> %s\n", root->name);
    }
    for  (int i=0; i<26; i++) {
        if (root->list[i] != NULL) {
            display_all(root->list[i]);
        }
    }
}

void display_all_nodes(void) {
    display_all(head);
}

int delete_node(char *name) {

    struct node *tmp = head; 
    while (*name) {
        if (tmp == NULL) {
            printf("Delete : No name found\n");
            return 0; //Breaking in between
        }
        tmp = tmp->list[*name-97];
        name++;
    }

    tmp

}

int test_trie()
{
    head = calloc(1, sizeof(struct node));

    insert("kamal");
    insert("kiran");
    insert("kamal");
    insert("kiran");

    insert("anil");
    insert("sunil");

    printf("Search result = %d\n", search("kamal"));
    printf("Search result = %d\n", search("kishore"));

    display_all_nodes();
    return 0;
}

