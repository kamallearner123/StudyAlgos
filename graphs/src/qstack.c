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
        rearQ = calloc(1, sizeof(struct Queue));
    } else {
        rearQ->next = calloc(1, sizeof(struct Queue));
        rearQ = rearQ->next;
    }

    rearQ->data = data;
    return;
}


void * GetFromQ() {
    void *data;
    struct Queue *tmp;
    if (frontQ == rearQ) {
        printf("###Empty Q\n");
        return NULL;
    } else {
        data = frontQ->data;
        tmp = frontQ;
        frontQ = frontQ->next;
        free(tmp);
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
