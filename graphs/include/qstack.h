#include<stdio.h>

struct Queue {
    void *data;
    struct Queue *next;
};

struct Stack {
    void *data;
    struct Stack *next;
};

void initQ(void);