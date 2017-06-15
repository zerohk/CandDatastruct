//输入一个整数，循环打印1234567890
#include<stdio.h>
int main(void)
{
	int a;
	int j = 1;
	printf("请输入一格1整数：");
	scanf("%d", &a);

	while (a <= 0)
	{
		printf("请输入一格1整数：");
		scanf("%d", &a);
	}
	for (int i = 1; i <= a; i++)
	{
		
			printf("%d", j++);
		if (j == 10)
			j = 0;
	}
	getchar();
	return 0;
}
