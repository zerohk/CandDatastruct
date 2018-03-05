#include <stdio.h>

int main(void) {
    int len;
    int arr[] = {4,6,7,3,2,8,5,1,9};
    len = (int) sizeof(arr) / sizeof(*arr);
    print(arr,len);
    bubbleSort(arr,len);
    print(arr,len);
    return 0;
}

void bubbleSort(int arr[],int len)
{
    int temp,i,j;
    for(i = 0;i < len - 1;i++)
        for(j = 0;j < len -  1 - i;j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
}

void print(int a[],int len)
{
    for(int i = 0;i < len;i++)
    {
        printf("%d  ",a[i]);
    }
    printf("\n");

}
