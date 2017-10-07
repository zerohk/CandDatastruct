#include<stdio.h>
#include<malloc.h>
  /*malloc();*/
#include<stdlib.h>
 //exit();

struct Arr 
{
	int * pBase;//存放数组的首地址
	int cnt; //当前数组有效元素个数
	int len; //数组能容纳的元素的最大个数
};

void init_arr(struct Arr *pArr,int length);
bool is_empty(struct Arr *pArr);
void show_arr(struct Arr *pArr);
bool append(struct Arr * pArr,int val);
bool insert(struct Arr *pArr ,int pos,int val);
bool delete_arr(struct Arr *pArr,int pos ,int * pVal);
void inversion_arr(struct Arr *pArr);
void sort_arr(struct Arr *pArr);

int main(void)
{
	struct Arr arr;
	int val;
	init_arr(&arr,6);
	show_arr(&arr);
	append(&arr,1);
	append(&arr,2);
	append(&arr,3);
	append(&arr,4);
	show_arr(&arr);
    insert(&arr,2,88);
	show_arr(&arr);
	delete_arr(&arr,2,&val);
	printf("删除的元素是:%d\n",val);
	show_arr(&arr);
	inversion_arr(&arr);
	printf("倒置后的数组为:\n");
	show_arr(&arr);
	sort_arr(&arr);
	printf("排序后的数组为:\n");
	show_arr(&arr);
	
	
	
	return 0;	
}

void init_arr(struct Arr *pArr,int length)
{
	pArr->pBase = (int *) malloc(sizeof(int) * length);
	if(NULL == pArr->pBase)
	{
	    printf("内存空间分配失败");
	    exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

bool is_empty(struct Arr * pArr)
{
	if(pArr->cnt == 0)
	return true;
	else
	return false;
}

bool is_full(struct Arr * pArr)
{
	if(pArr->cnt==pArr->len)
	return true;
	else
	return false;
}

void show_arr(struct Arr * pArr)
{
	if(is_empty(pArr))
	printf("数组为空\n");
	else
	{
		for(int i = 0;i<pArr->cnt;++i)
		printf("%4d",pArr->pBase[i]);
	}
	printf("\n");
}

bool append(struct Arr *pArr,int val)
{
	if(is_full(pArr))
	return false;
	
	pArr->pBase[pArr->cnt] = val;
	pArr->cnt++;
	return true;
}

bool insert(struct Arr *pArr,int pos,int val)
{
	if(is_full(pArr))
	return false;
	if(pos<1|| pos > pArr->cnt + 1)
	return false;
	int i;
	for(i=pArr->cnt-1;i>=pos-1;--i)
	pArr->pBase[i+1] = pArr->pBase[i];
	pArr->pBase[pos-1]=val;
	pArr->cnt++;
	return true;
}

bool delete_arr(struct Arr *pArr,int pos ,int * pVal)
{
	if(is_empty(pArr))
	return false;
	if(pos<1||pos>pArr->cnt)
	return false;
	*pVal = pArr->pBase[pos-1];
	int i;
	for(i = pos;i < pArr->cnt;++i)
	pArr->pBase[i-1] = pArr->pBase[i];
	pArr->cnt--;
	return true;
}

void inversion_arr(struct Arr *pArr)
{
	int i=0;
	int j=pArr->cnt-1;
	int t;
	while(i<j)
	{
		t=pArr->pBase[i];
		pArr->pBase[i]=pArr->pBase[j];
		pArr->pBase[j]=t;
		++i;--j;
	}
	return;
}

void sort_arr(struct Arr *pArr)
{
	int i,j;
	for(i=0;i<pArr->cnt;++i)
	{
		for(j=i+1;j<pArr->cnt;++j)
		{
			if(pArr->pBase[i]>pArr->pBase[j])
			{
				int t;
				t=pArr->pBase[i];
				        pArr->pBase[i]=pArr->pBase[j];
				        pArr->pBase[j]=t;
			}
		}
	}
}
				


	
