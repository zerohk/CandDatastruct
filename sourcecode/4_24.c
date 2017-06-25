/*

练习4-18
编写一段程序，输入一个整数，像右面这样显示出输入整数层的金字塔形状。
让我们来描绘一个金字塔。
金字塔有几层：3
*
***
*****
*/

 1 #include "stdio.h"
 2
 3     int main(int argc, char const *argv[])
 4     {
 5         int n;
 6         puts("让我们来描绘一个金字塔。");
 7         printf("金字塔有几层:"); scanf("%d",&n);
 8
 9         for (int i = 1;i<=n; i++) {
10             for (int j = 1; j<=n-i; j++) {
11                 putchar(' ');
12             }
13             for (int j=1;j<=i ; j++) {
14                 putchar('*');
15             }
16             for (int j=1; j<i; j++) {
17                 putchar('*');//懂了，相当于在三角形后面加*
18             }
19             putchar('\n');
20
21         }
22             return 0;
23     }
