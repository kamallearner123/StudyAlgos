#include <stdio.h>

void print_subarray(int a[], size_t arr_len)
{
    printf("Array size is %lu\n", arr_len);

    int offset=0, offset1=0, len=0, len1=0, i, num1, num2;
    int flag = 0;

    for(i=1; i<arr_len; i++)
    {
        if (!((a[i]-a[i-1]) > 1 || (a[i]-a[i-1]) < -1)) {

            offset = i-1;
            len =1;

            //0,0,0,1,2,3,4,1,2,3,4//
            if (flag == 0 && a[i] != a[i-1])
            {
                num1 = a[i];
                num2 = a[i-1];
                flag = 1;
            }

            i = i+1;
            
            for (; (i<arr_len) && (!((a[i]-a[i-1]) > 1 || (a[i]-a[i-1]) < -1)) && ((flag ==0) || (a[i] == num1 || a[i]== num2)); i++)
            {
                if (flag == 0 && a[i] != a[i-1])
                {     
                    num1 = a[i]; //1
                    num2 = a[i-1];//0                                                                                                          
                    flag = 1;
                } 

                len +=1;    
            }

            flag = 0;

            if (len > len1) {
                offset1= offset;
                len1 = len;
            }
        }

        printf("offset = %d, len = %d\n",offset, len);
    }

    for(i=offset1; i<=offset1+len1; i++)
    {
        printf("%d,",a[i]);
    }

}

int main()
{
    int array[] = {9,0,9,9,9,9,9,9,9,9,9,9,9,9,1,1,2,2,0,0,0,0,3,3,4,4,4,4,0,-1,-1,-1,0,-1,-1,0,10};

    print_subarray(array, sizeof(array)/sizeof(array[0]));
}
