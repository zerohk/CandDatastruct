/*******
******
仿4_24做的


第i航显示i%10

11111
 222
  3
*/


#include<stdio.h>

int main(void)
{
	int i, j, m, n;
	printf("请输入金字塔的层数:"); scanf("%d", &n);

	for (i = 1; i <= n;i++) //控制行数
	{
		for (j = n; j >= n-i; j--)
			printf(" ");
		for (j= n; j>=i; j--)
			printf("%d",i%10);
		for (j = n; j > i; j--)
			printf("%d",i%10);
		printf("\n");

	}

	getchar();
	return 0;
}
