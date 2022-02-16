#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct RBNode {
    bool black;
    struct RBNode *left;
    struct RBNode *right;
    int key;
};

void rb_insert(int);
void rb_displayall(void);

