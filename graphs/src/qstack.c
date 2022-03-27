#include <stdio.h>
#include "qstack.h"

/*
Queue:
1) Init Q
2) InsertInQ
3) GetFromQ
4) DestroyQ
*/

//static struct Queue stheadQ;
//static struct Queue *headQ;
static struct Queue *frontQ = NULL;
static struct Queue *rearQ = NULL;

// void initQ(void) {
//     headQ = &stheadQ;
//     frontQ = headQ;
//     rearQ = headQ;
//     return;
// }

void InsertInQ(void *data) {
    if (rearQ == NULL) {
        rearQ = calloc(1, sizeof(struct Queue));//4000
        rearQ->next = NULL;
        frontQ = rearQ;//frontQ = 4000
    } else {
        rearQ->next = calloc(1, sizeof(struct Queue));//4000->next = 5000
        rearQ = rearQ->next;//rearQ = 5000
        rearQ->next = NULL;
    }

    rearQ->data = data;
    return;
}


void * GetFromQ() {
    void *data;
    struct Queue *tmp;
    if (frontQ == NULL) {
        printf("###Empty Q\n");
        return NULL;
    } else {
        tmp = frontQ; //tmp -> 4000: tmp = 5000
        data = frontQ->data;
        frontQ = frontQ->next;//frontQ = 5000: from! = NULL
        free(tmp); //free 4000
        if (frontQ == NULL) {
            rearQ = NULL;
        }
    }
    return data;
}



void destroyQ() {
  struct Queue *tmp;

  while(frontQ != NULL)
  {
    tmp = frontQ;
    frontQ = frontQ->next;
    free(tmp);
  }
  rearQ = NULL;
  return;
}


/*
Stack:
1) Init Stack
2) Push
3) Pop
4) DestroyStack
*/

static struct StackNode *top = NULL;

void insertInStack(void *data)
{
   if(NULL == top)
    {
        top = calloc(1, sizeof(struct StackNode));
        top -> next = NULL;
        top -> prev = NULL;
    }
   else
      {
        top -> next = calloc(1, sizeof(struct StackNode));
        top -> prev = top;
        top = top -> next; 
      }
      top -> data = data;
      return;
}

int* popFromStack()
{
   int* data;
   struct StackNode *tmp;
   if(top == NULL)
     {
       printf("empty stack \n");
     }
   else
     {
       data = top -> data;
       tmp = top;
       top = top -> prev;
       if(top != NULL)
         top -> next = NULL;
       free (tmp);             
     }
   return data;
}


void destroyStack() {
  struct StackNode *tmp;

  while(top != NULL)
  {
    tmp = top;
    top = top->prev;
    free(tmp);
  }
  return;
}

