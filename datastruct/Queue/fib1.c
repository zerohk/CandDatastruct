/*
 * 斐波那契数列，用迭代方式实现
 * 采用数组存储方式
 * n < 2 f(n) = n;
 * n >= 2 f(n) = f(n - 1) + f(n - 2);
 */


#include <stdio.h>
#define MAXSIZE 50
int main() {
    int leng;
    int a[MAXSIZE];
    printf("你想输出前多少位的斐波那契数列？\n");
    scanf("%d",&leng);
    a[0] = 0;
    a[1] = 1;
    printf("前%d位的斐波那契数列是：",leng);
    printf("%d  %d  ",a[0],a[1]);
    for(int i = 2;i < leng;i++)
    {
        a[i] = a[i-1] + a[i-2];
        printf("%d  ",a[i]);
    }
    return 0;
}
