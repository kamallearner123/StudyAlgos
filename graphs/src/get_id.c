#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_base2(int num) {
    int bits = 0;

    while (num!= 0) {
        bits ++;
        num /= 2;
    }
    return bits;
}

long power_to(long base, long power) {
    long total = 1;
    while (power >= 1) {
        total *= base;
        power--;
    }

    return total;
}

char *key;
char *gcombs;
int gcombs_len;
char *poss;
int gpos;
int key_len;

int sub_key(int pos) {
    if (pos>=key_len)
        return -1;
    while(poss[pos]<gcombs_len) {
        key[pos] = gcombs[poss[pos]];
        if (-1 != sub_key(pos+1)) {
            return 0;
        };
        poss[pos] += 1;
    }
    poss[pos] = 0;
    gpos++;
    return -1;
}

void gen_seq(char *combs, int len) {

    key = calloc(1, len+1);
    key_len = len;
    gcombs = malloc(strlen(combs)+1);
    strncpy(gcombs, combs, strlen(combs));
    gcombs_len = strlen(combs);
    poss = calloc(1, len);
}

int main()
{
    gen_seq("abc", 3);
    for (int i=0; i<10; i++) {
        sub_key(gpos);
        printf("Key = %s\n",key);
        for (int j=0; j<key_len; j++) {
            printf("%d", poss[j]);
        }
        printf("\n");
    }
    return 0;
}