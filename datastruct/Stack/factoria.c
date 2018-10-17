#include <stdio.h>

int factoria(int i);

int main(void)
{
    int i;
    printf("你想计算谁的阶乘？\n");
    scanf("%d",&i);
    int factor = factoria(i);
    printf("%d的阶乘为%d\n",i,factor);
}

int factoria(int i)
{
    if(i == 0)
        return 1;
    else
        return i * factoria(i - 1);
}
