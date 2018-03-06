include <stdio.h>
int binarySearch(int *arr,int searchNum);
void judge(int number,int searchNum);

int main() {
    int arr[] = {2,3,14,23,32,45,68,75,88,100,120,341,400};
    printf("Please input the num u want search:");
    int sNum ;
    scanf("%d",&sNum);
    int number = binarySearch(arr,sNum);
    printf("%d",number);
    //judge(number,sNum);

    return 0;
}

int binarySearch(int *arr,int searchNum)
{
    int ret = -1;
    int len = (int) sizeof(arr) / sizeof(arr[0]);
    int start = 0;
    int end = len - 1;

    while(end >= start)
    {
        int m = start + (end - start) / 2;
        if(arr[m] > searchNum)
            end = m - 1;
        else
        if(arr[m] < searchNum)
            start = m + 1;
        else
        if(arr[m] == searchNum)
        {
            ret = m;
            break;
        }

    }
    return ret;
}

void judge(int number,int searchNum)
{
    if(number == -1)
        printf("search fail");
    printf("%d is locates %d",searchNum,number + 1);
}
