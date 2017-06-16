//输入一个数n，打印n个*，每五个*换行
#include<stdio.h>
int main(void)
{
	int a, i;
	int j = 1;
	printf("请输入一个整数："); scanf("%d", &a);
	for (i = 1; i <= a; i++)
	{
		printf("*");
		if (i % 5 == 0)
			printf("\n");
	}
	printf("\n");
	getchar();
	return 0;
}
