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




/*
Stack:
1) Init Stack
2) Push
3) Pop
4) DestroyStack
*/
