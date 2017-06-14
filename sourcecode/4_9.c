//输入一个数，交替打印+-的个数为输入的数个数
#include<stdio.h>
int main(void)
{
	int no;
	int i = 1;
	printf("请输入一个整数："); scanf("%d",&no);
	while (i <= no) {
		if (i % 2 != 0)
			printf("+");
		else
			printf("-");
		i++;
	}
	getchar();
	return 0;
}
