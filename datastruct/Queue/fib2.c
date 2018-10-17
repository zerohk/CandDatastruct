//
// Created by zerohk on 2018/10/17.
//

#include <stdio.h>

int fib(int n);
int main(void)
{
    printf("递归计算前四十位的斐波那契数列\n");
    fib(40);
    return 0;
}

int fib(int n)
{
    if(n < 2)
        return (n == 0)?0:1;
    return fib(n-1) + fib(n-2);
}
