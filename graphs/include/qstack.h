#include<stdio.h>

struct Queue {
    void *data;
    struct Queue *next;
};

void initQ(void);