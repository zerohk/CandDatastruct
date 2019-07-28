//线性表的顺序存储实现。
//将线性表当成数组处理。
#include <stdio.h>
#include <malloc.h>
#include <cstdlib>


#define ElemType int
#define MaxSize 100


//结构定义
typedef struct SqList
{
    ElemType *base;//数组元素的基址
    int length;//数组的当前长度
    int listSize;//当前分配的最大空间,以sizeof(ElemType)为单位
}SqList;


//线性表基本操作函数声明
bool InitList(SqList &L);//初始化线性表，构造一个空的线性表
bool DestoryList(SqList &L);//线性表已存在，销毁线性表
void ClearList(SqList &L);//线性表已存在，清空线性表
bool ListEmpty(SqList &L);//判空
int ListLength(SqList &L);//返回线性表长度
int GetElem(SqList &L,int i,int *e);//用e返回第i个位置的值 LocateElem(SqList &L,int e);//若e存在线性表，则返回位序，否则返回0
bool ListInsert(SqList &L,int i,int e);//第i个位置插入e
int ListDelete(SqList &L,int i,int *e);//删除第i个位置的元素，并保存在e内
void ListTraverse(SqList &L);//遍历顺序表
bool LocateElem(SqList &L,int e);//判断元素e是否存在于L中
void Union(SqList &La,SqList &Lb);//A=AUB
void MergeList(SqList &La,SqList &Lb,SqList &Lc);

bool InitList(SqList &L)
{
    L.base = (ElemType *)malloc(MaxSize * sizeof(ElemType));
    if(!L.base)
        return false;//
    L.length = 0;
    L.listSize = MaxSize;
    return true;
}


bool ListEmpty(SqList &L)
{
    if(L.length == 0)
        return true;
    return false;
}


int ListLength(SqList &L)
{
    return L.length;
}


int GetElem(SqList &L,int i,int *e)
{
    if(i < 1||i > L.length)
    {
        printf("位置有误！\n");
        exit(-1);
    }
    if(ListEmpty(L))
    {
        printf("数组为空！\n");
        exit(-1);
    }
    *e = L.base[i-1];
    return *e;
}


bool LocateElem(SqList &L,int e)
{
    for(int i = 0;i < L.length;i++)
        if(L.base[i] == e)
            return true;
    return false;
}


bool ListInsert(SqList &L,int i,int e)
{
    if(i < 1||i > L.length + 1)
    {
        printf("插入位置有误！\n");
        return false;
    }
    if(L.length == L.listSize)
    {
        printf("存储空间已满！无法插入\n");
        return false;
    }
    for(int j = L.length;j>=i;j--)
    {
        L.base[j] = L.base[j-1];
    }
    L.length++;
    L.base[i-1] = e;
    return true;
}


int ListDelete(SqList &L,int i,int *e)
{
    if(i<1||i>L.length)
    {
        printf("删除位置有误！\n");
        exit(-1);
    }
    *e = L.base[i-1];
    for(int j = i-1;j<L.length-1;j++)
    {
        L.base[j] = L.base[j+1];
    }
    L.length--;
    return *e;
}

void ListTraverse(SqList &L)
{
    printf("数组的元素依次为：\n");
    for(int i = 0;i < L.length-1;i++)
    {
        printf("%d, ",L.base[i]);
    }
    printf("%d\n",L.base[L.length-1]);
}


void Union(SqList &La,SqList &Lb)
{
    int vb;
    for(int i = 1;i <= Lb.length;i++)
    {
        GetElem(Lb,i,&vb);
        if(!LocateElem(La,vb))
            ListInsert(La,La.length+1,vb);
    }
}//时间复杂度为O(La.length x Lb.length);


void MergeList(SqList &La,SqList &Lb,SqList &Lc)
{
    int i=0,j=0,k=1;
    while(i<La.length && j<Lb.length)
    {
        if(La.base[i] >= Lb.base[j])
        {
            ListInsert(Lc,k,La.base[i]);
            i++;
            k++;
        }
        else
        {
            ListInsert(Lc,k,Lb.base[j]);
            j++;
            k++;
        }
    }
    while (i<La.length)
    {
        ListInsert(Lc,k,La.base[i]);
        i++;
        k++;
    }
    while(j<Lb.length)
    {
        ListInsert(Lc,k,Lb.base[j]);
        j++;
        k++;
    }
}//时间复杂度为O(La.length + Lb.length)


 int main(void)
{
    int value;
    SqList L;
    InitList(L);
    if(ListEmpty(L))
        printf("数组为空！\n");

    SqList La,Lb;
    InitList(La);
    InitList(Lb);
    ListInsert(La,1,1);
    ListInsert(La,2,2);
    ListInsert(La,3,3);
    ListInsert(La,4,4);
    ListInsert(La,5,5);
    ListInsert(La,6,6);
    ListInsert(La,7,7);
    ListTraverse(La);
    ListInsert(Lb,1,8);
    ListInsert(Lb,1,9);
    ListInsert(Lb,1,7);
    ListInsert(Lb,1,10);
    ListInsert(Lb,1,2);
    ListTraverse(Lb);
    GetElem(La,5,&value);
    printf("%d\n",value);
    Union(La,Lb);
    ListTraverse(La);
    ListDelete(La,3,&value);
    printf("删除的元素是%d\n",value);
    ListTraverse(La);


    printf("----------------------------------------\n");
    SqList Laa;
    SqList Lbb;
    SqList Lcc;
    InitList(Laa);
    InitList(Lbb);
    InitList(Lcc);
    ListInsert(Laa,1,10);
    ListInsert(Laa,2,9);
    ListInsert(Laa,3,5);
    ListInsert(Laa,4,3);
    ListInsert(Lbb,1,9);
    ListInsert(Lbb,2,8);
    ListInsert(Lbb,3,7);
    ListTraverse(Laa);
    ListTraverse(Lbb);
    MergeList(Laa,Lbb,Lcc);
    ListTraverse(Lcc);
}
