#include <stdio.h>
    int q[10] = {0};
    int push_p=-1, pop_p=-1;
int push(int val) {
    if (push_p == -1) 
        push_p = 0;

    if (push_p >= 10)
        push_p %= push_p;

    if (push_p+1 == pop_p) {
        printf("Q is full");
        return -1;
    }

    q[push_p] = val;
    push_p++;

    if (pop_p == -1)
        pop_p = 0;
}

int main() {
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(11);
    push(-10);
    for (int i=0; i<sizeof(q)/sizeof(q[0]); i++)
        printf(" %d", q[i]);
    return 0;
}

