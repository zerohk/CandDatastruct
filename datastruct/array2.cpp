#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>



typedef struct Array
{
	int length;   //顺序表的最大长度
	int cnt;      //当前顺序表的有效元素个数
	int * pBase;   //顺序队列的首地址
}ARRAY,*PARRAY;

void init_array(PARRAY pArr,int length);//初始化数组
bool append(PARRAY pArr, int val);//插入元素
bool delete_arr(PARRAY pArr, int pos,int * val);//删除元素
bool show(PARRAY pArr);//显示数组。
bool empty(PARRAY pArr);//判断数组是否为空
bool full(PARRAY pArr);//判断数组是否满
bool insert_arr(PARRAY pArr, int pos, int val);
void sort_arr(PARRAY pArr);



int main(void)
{
	struct  Array arr;
	int length;
	int val;
	int pos;
	int val1;
	printf("请输入数组的最大长度：");
	scanf("%d", &length);
	init_array(&arr,length);
	show(&arr);
	printf("请输入需要插入的元素：(9999停止输入)");
	scanf("%d", &val);
	while (val != 9999)
	{
		append(&arr, val);
		printf("插入%d后的数组为：", val);
		show(&arr);
		printf("请输入需要插入的元素：(9999停止输入)");
		scanf("%d", &val);
	}

	printf("你想要删除那个位置的元素？");
	scanf("%d", &pos);
	delete_arr(&arr, pos, &val1);
	printf("删除的元素是：");
	printf("%d\n", val1);
	printf("删除该元素后的数组为：");
	show(&arr);
	printf("请输入你想要插入的元素：");
	int val2;
	scanf("%d", &val2);
	int pos2;
	printf("请输入你需要插入到哪个位置");
	scanf("%d", &pos2);
	insert_arr(&arr, pos2, val2);
	printf("插入%d后的数组为：", val2);
	show(&arr);
	printf("排序后的数组为：");
	sort_arr(&arr);
	show(&arr);
	scanf("%d", &pos);
	return 1;
}


void init_array(PARRAY pArr,int length)
{
	pArr->pBase = (int *)malloc(sizeof(int)*length);
	if (NULL == pArr->pBase)
	{
		printf("内存分配失败！");
		exit(-1);
	}
	else {
		pArr->length = length;
		pArr->cnt = 0;
	}
	return;
}
bool show(PARRAY pArr)
{
	int i = 0;
	if (empty(pArr))
	{
		printf("数组为空！\n");
		return false;
	}
	else
	{
		while (i<pArr->cnt)
		{
			printf("%3d", pArr->pBase[i]);
			i++;
		}
		printf("\n");
		return true;
	}
}
bool empty(PARRAY pArr)
{
	if (pArr->cnt == 0)
		return true;
	else
		return false;
}
bool full(PARRAY pArr)
{
	if (pArr->cnt == pArr->length)
		return true;
	else
		return false;
}
bool append(PARRAY pArr, int val)
{
	if (full(pArr))
	{
		printf("数组已满！");
		return false;
	}
	else
	{
		pArr->pBase[pArr->cnt] = val;
		pArr->cnt++;
		return true;
	}

}
bool delete_arr(PARRAY pArr,int pos,int * val)
{
	if (empty(pArr))
	{
		printf("数组为空!");
		return false;
	}
	if (pos<1 || pos>pArr->cnt)
		return false;
	else
	{
		*val = pArr->pBase[pos - 1];
		for (int i = pos; i <pArr->cnt; ++i)
		{
			pArr->pBase[i - 1] = pArr->pBase[i];
		}
		pArr->cnt--;
		return true;

	}
}
bool insert_arr(PARRAY pArr, int pos, int val)
{
	if (full(pArr))
	{
		printf("数组已满！");
		return false;
	}
	if (pos<1 || pos>pArr->cnt+1)
		return false;
	
	for (int i = pArr->cnt-1; i >= pos-1; --i)
		pArr->pBase[i+1] = pArr->pBase[i];
	pArr->pBase[pos - 1] = val;
	pArr->cnt++;
	return true;
}
void sort_arr(PARRAY pArr)
{
	int i, j;
	for (i = 0; i < pArr->cnt; i++)
	{
		for (j = i + 1; j < pArr->cnt; j++)
		{
			if (pArr->pBase[i] < pArr->pBase[j])
			{
				int t;
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;

			}
				
		}
	}
		
}
