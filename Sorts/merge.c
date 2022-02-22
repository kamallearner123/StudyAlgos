#include <stdio.h>




void selection_sort(int arr[], int len) {

    int index, i, j, tmp;

    //34,6,0,9,8,71,23,5,4,1
    for (j=0; j<len; j++) {
        index = j;
        
        for (i=j+1; i<len; i++) {
            if (arr[i] < arr[index]) {
                index = i;
            }
        }

        tmp = arr[j];
        arr[j] = arr[index];
        arr[index] = tmp;
    }
}

void bubble_sort(int arr[], int len) {
    
    int i,j, tmp;

    printf("len = %d\n", len);

    for (j=0; j<len; j++)
    {
        for (i=0; i<len-1-j; i++)
        {
            if (arr[i]>arr[i+1]) {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
            }
        }

    }
}


void print_array(int arr[], int len) {
    int i;
    for (i= 0; i< len; i++)
        printf(" %d", arr[i]);

    printf("\n");
}

int main()
{

    int arr[10] = {34,6,0,9,8,71,23,5,4,1};
    int arr2[10] = {34,6,0,9,8,71,23,5,4,1};
    bubble_sort(arr, sizeof(arr)/sizeof(int));
    print_array(arr, sizeof(arr)/sizeof(int));
    selection_sort(arr, sizeof(arr2)/sizeof(int));
    print_array(arr, sizeof(arr2)/sizeof(int));
    return 0;
}
