//打印直角在右上角的等腰三角形

#include<stdio.h>
int main()
{
	int len;
	int i, j;
	puts("打印直角在右上角的等腰三角形");
	printf("直角边的长度："); scanf("%d", &len);


	for (i = len; i >= 1; i--)
	{
		for (j = len; j > i; j--)
			putchar(' ');
		for (j = 1; j <= i; j++)
			printf("*");
		putchar('\n');
	}

	getchar();
	return 0;
		
}
