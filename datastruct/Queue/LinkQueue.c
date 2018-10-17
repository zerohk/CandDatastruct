#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}NODE,*QNODE;
typedef struct LinkQueue
{
    QNODE front;
    QNODE rear;
}LINKQUEUE;

void InitQueue(LINKQUEUE *q);
void InsertQueue(LINKQUEUE *q,ElemType e);
void DeleteQueue(LINKQUEUE *q,ElemType *e);

int main() {
    printf("请输入队列元素，输入'#'结束\n");
    char c;
    LINKQUEUE q;
    InitQueue(&q);
    scanf("%c",&c);
    while (c != '#')
    {
        InsertQueue(&q,c);
        scanf("%c",&c);
    }
    printf("您输入的队列为：");
    char e;
    while (q.front != q.rear)
    {
        DeleteQueue(&q,&e);
        printf("%c",e);
    }
    return 0;
}

void InitQueue(LINKQUEUE *q)
{
    q->front = q->rear = (QNODE)malloc(sizeof(NODE));
    if(!q->front)
        exit(0);
    q->front->next = NULL;
}

void InsertQueue(LINKQUEUE *q,ElemType e)
{
    QNODE p = (QNODE)malloc(sizeof(NODE));
    if(!p)
        exit(0);
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

void DeleteQueue(LINKQUEUE *q,ElemType *e)
{
    if(q->front == q->rear)
        return;
    QNODE p;
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p)
        q->rear = q->front;
    free(p);
}
