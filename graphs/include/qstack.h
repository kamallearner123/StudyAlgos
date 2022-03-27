#include<stdio.h>


#ifndef __GSTACK_H__
#define __GSTACK_H__

struct Queue {
    void *data;
    struct Queue *next;
};

struct StackNode
{
    int data;
    struct StackNode *next;
    struct StackNode *prev;
};


void insertInStack(void *data);
int* popFromStack();
void destroyStack();

void * GetFromQ();
void InsertInQ(void *data);
void destroyQ();

#endif