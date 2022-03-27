#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;

    for(i=0; i<numsSize; i++) {
        for (j=i+1; j<numsSize; j++) {
            printf("i = %d, j = %d\n", nums[i], nums[j]);
            if (nums[i]+nums[j] == target) {
                printf("*****Matched*********\n");
                *returnSize = i;
                *(returnSize+1) = j;

                return NULL;

            }
        }
    }
}

int main() {

	int arr[] = {3,5,7,9,3,4,66,8,0};
	int target = 10;

	int index[2];

	twoSum((int*)arr, sizeof(arr)/sizeof(int), target, (int *)index);
    printf(" [%d,%d]\n", *index, *(index+1));
    return 0;
}
