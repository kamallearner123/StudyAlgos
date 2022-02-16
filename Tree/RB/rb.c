#include "rb.h"


struct RBNode *root;


void insert_internal(struct RBNode *parent, 
                struct RBNode *child) {
    
    if (child->key > parent->key) {

    }

}
void rb_insert(int num) {
    struct RBNode **curr, *prev, *new = calloc(1, sizeof(struct RBNode)); // 2. New insertion is red
    new->key = num;

    curr = &root;
    while(*curr) {
        if (new->key > (*curr)->key) {
            curr = &((*curr)->right);
        } else {
            curr = &((*curr)->left);
        }
    }

    if (root == NULL)
        new->black = true; //1. Root should be black

    *curr = new;

    return;
}

void display(struct RBNode *node) {
    if (node == NULL) {
        return;
    }

    display(node->left);
    printf("Num = %d\n", node->key);
    display(node->right);
    return;
}

void rb_displayall(void) {
    display(root);
    return;
}