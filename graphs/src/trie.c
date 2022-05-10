#include "trie.h"

#define MAX_NUM_OF_TRIE 10
struct node g_head;
struct node *ga_head[MAX_NUM_OF_TRIE];
int gtop = -1;

struct node *head = &g_head;

int init_trietree() {
    gtop++;
    int i;
    //Search for NULL entry//
    for (i=0; i<MAX_NUM_OF_TRIE; i++) {
        if (ga_head[i] == NULL) {
            ga_head[i] = (struct node*)malloc(sizeof(struct node ));
            return i;
        }
    }

    return -1;
}

void destroy_trietree(int index)
{
    free(ga_head[index]);
    ga_head[index] = NULL;
}

void inc_ref_count(int index, char *name) {
    struct node *tmp = ga_head[index];
    while (*name) {
        tmp->ref_count ++; //Incrementing ref count for the node.
        printf("Increasing ref count for %c\n", *name);
        tmp = tmp->list[*name-97];
        name++;
    }
}


int insert (int index, char *iname) {
    struct node *tmp = ga_head[index];
    char *name;
    name = iname;

    if (search(index, name) != NULL) {
        printf("%s: Name = %s : Duplicate insertion\n", __FUNCTION__, iname);
        return 0;
    }

    //traverse for each letter//
    while (*name) { //"kamal" = 'k', 'a', 'm', a , l
        if (tmp->list[*name-97] == NULL) { //Check node for current letter is created or not
            printf("Allocating memory for %c\n", *name);
            tmp->list[*name-97] = calloc(1, sizeof(struct node));
        }
        tmp->ref_count++;
        tmp = tmp->list[*name-97];
        name++;
    }

    tmp->name =  strndup(iname, 100);
    tmp->ref_count++;

    return 0;
}

struct node * search(int index, char *name) {
    struct node *tmp = ga_head[index];
    while (*name) {
        if (tmp == NULL) {
            return 0; //Breaking in between
        }
        tmp = tmp->list[*name-97];
        name++;
    }

    if (tmp == NULL) {
        return NULL; //FAILED
    }

    if (tmp->name == NULL) {
        return NULL; //FAILED
    }
    else {
        return tmp;
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

void display_all_nodes(int index) {
    if (ga_head[index] == NULL) {
        return;
    }
    struct node *head = ga_head[index];
    display_all(head);
}


static void delete_friends_list(struct node *account) {
    for (int i=0; i<MAX_FRIENDS; i++) {
        if (account->friends[i] != NULL) {
            free(account->friends[i]);
        }
    }
}


int delete_node(int index, char *iname) {
    char *name = iname;
    struct node *curr = ga_head[index];
    struct node *prev = NULL; 

    if (search(index, name)==0) {
        printf("%s: Name = %s : Failed to find\n", __FUNCTION__, iname);
        return 0;
    }
    while (*name) {
        prev = curr;
        curr = prev->list[*name-97];
        if (curr == NULL) {
            printf("Delete : No name found\n");
            return 0; //Breaking in between
        }

        if ((prev->ref_count == 1) 
         && (prev != head)) {
            free(prev);
        }
        else {
            prev->ref_count--;
        }
        name++;
    }

    //curr points to the node which has to be deleted. 
    //If curr is not leaf node then delete just name.
    if (0 == strncmp(iname, curr->name, strlen(name))) {
        delete_friends_list(curr);
        free(curr->name);
        if (curr->ref_count == 1) {
            free(curr);
            return 1;
        } else {
            curr->ref_count--;
            curr->name = NULL;
            return 1;
        }
    } else {
        assert(0);
    }

    return 0;

}

int test_trie()
{
    int id = init_trietree();
    insert(id, "kamal");
    insert(id,"kiran");
    insert(id,"kamal");
    insert(id,"kiran");

    insert(id,"anil");
    insert(id,"sunil");

    printf("Search result = %p\n", search(id,"kamal"));
    printf("Search result = %p\n", search(id,"kishore"));
    printf("Search result = %p\n", search(id,"kama"));

    display_all_nodes(id);
    return 0;
}

