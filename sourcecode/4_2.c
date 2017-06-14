/*输出两个整数之间所有整数和*/
#include<stdio.h>
int main(void)
{
	int a;
	int b;
	int min,max;
	int sum=0;
	puts("请输入两个整数：");
	printf("第一个整数："); scanf("%d", &a);
	printf("第二个整数："); scanf("%d",&b);
	min = a;
	if (a <= b) {
		min = a;
		max = b;
	}
	else
	{
		min = b;
		max = a;
	}
	
		do
		{
			sum += min;
			min += 1;
		}while(min <= max);
	
		printf("大于等于%d小于等于%d的所有整数和是：%d\n", min, max, sum);
		getchar();
		return 0;
}
