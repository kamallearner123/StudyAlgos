#include<stdio.h>


int main() {
    int arr[] = {-3,100,4333,32,-50,5,8,0,1,5,7,9};

    int l,r,init_p = -1, p=-1,t;

    int len = sizeof(arr)/sizeof(int);
    for(int i =0; i<len; i++) {
        printf("%d ", arr[i]);
    }

    for (int i=0; i<len; i++) {
        l = 0;
        r = len-1;
        if (p == init_p) {
            init_p++;
        }
        p = init_p;

        while(l<r) {
            for(int i =0; i<len; i++) {
                printf("%d ", arr[i]);
            }
            printf("Pivot = %d, r = %d, l = %d\n", arr[p],arr[r],arr[l]);
            if (p==l) {
                r--;
                if (arr[p]>arr[r]) {
                    t = arr[p];
                    arr[p] = arr[r];
                    arr[r] = t;
                    p = r;
                }
            } else {
                l++;
                if (arr[p] < arr[l]) {
                    t = arr[l];
                    arr[l]=arr[p];
                    arr[p]=t;
                    p = l;
                }
            }


        }
    printf("\v");
       
    }

}
