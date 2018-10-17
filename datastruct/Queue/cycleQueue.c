#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define MAXSIZE 5//实际只有四个元素，少用一个元素来表明栈已经满了.队尾指针指向队尾元素的下一个地址

typedef char ElemType;
typedef struct cycleQueue
{
    ElemType *base;
    int front;
    int rear;
}CQUEUE;

void InitQueue(CQUEUE *cq);
void enQueue(CQUEUE *cq,ElemType e);
void outQueue(CQUEUE *cq,ElemType *e);

int main() {
    CQUEUE cqueue;
    InitQueue(&cqueue);
    char e;
    outQueue(&cqueue,&e);
    enQueue(&cqueue,1);
    enQueue(&cqueue,2);
    enQueue(&cqueue,3);
    enQueue(&cqueue,4);
    enQueue(&cqueue,5);
    enQueue(&cqueue,6);
    outQueue(&cqueue,&e);
    outQueue(&cqueue,&e);
    outQueue(&cqueue,&e);
    outQueue(&cqueue,&e);
    outQueue(&cqueue,&e);
    return 0;
}

void  InitQueue(CQUEUE *cq)
{
    cq->base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    if(!cq->base)
        exit(0);
    cq->front = cq->rear = 0;
}

void enQueue(CQUEUE *cq,ElemType e)
{
    if((cq->rear + 1) % MAXSIZE == cq->front)
    {
        printf("栈满！\n");
        return;
    }

    cq->base[cq->rear] = e;
    cq->rear = (cq->rear + 1) % MAXSIZE;
    printf("入栈成功！\n");
}

void outQueue(CQUEUE *cq,ElemType *e)
{
    if(cq->front == cq->rear)
    {
        printf("栈为空！\n");
        return;
    }

    *e = cq->base[cq->front];
    cq->front = (cq->front + 1) % MAXSIZE;
    printf("出栈成功！\n");
}

