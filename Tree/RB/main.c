#include "rb.h"

int main()
{
    int nums[10] = {23,4,56,7,3,1,2,5,66,9}; 
    int num,count = sizeof(nums)/sizeof(int);
    while(count!=0) {
        num = nums[count-1];
        rb_insert(num);
        count--;
    }
        rb_displayall();

    printf("ret = %d\n", rb_delete(9));
    printf("ret = %d\n", rb_delete(45));
    rb_displayall();
}