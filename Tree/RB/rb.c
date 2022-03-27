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
            curr = RIGHT_REF(curr);
        } else {
            curr = LEFT_REF(curr);
        }
    }

    if ( (root == NULL))
        new->black = true; //1. Root should be black

    *curr = new;

    return;
}


#define LEFT_REF(node) &((*(node))->left)
#define RIGHT_REF(node) &((*(node))->right)

#define LEFT(node) (*(node))->left
#define RIGHT(node) (*(node))->right

struct RBNode ** find_node_ref(int data) {
    struct RBNode **tmp = &root;

    while (((*tmp) != NULL) && ((*tmp)->key != data)) {
        if (data >(*tmp)->key) 
            tmp = RIGHT_REF(tmp);
        else 
            tmp = LEFT_REF(tmp);
    }

    return tmp;
} 


int rb_delete(int num) {
//1) Find the node
    struct RBNode **mynode = find_node_ref(num);
    struct RBNode *left;

    if (*mynode == NULL)
        return -1;

//2) Adjust the children of the node 
//      - Link should not break
    if ((*mynode)->right == NULL) {
        *mynode = LEFT(mynode);
    } else {
        left = LEFT(mynode);
        while ((*mynode)->left != NULL) {
            mynode = LEFT_REF(mynode);
        }
        (*mynode)->left = left;
    }

//3) Delete the node 
    
    free(*mynode);
    return 0;
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
    if (root == NULL) {
        printf("root is NULL\n");
    }
    display(root);
    return;
}