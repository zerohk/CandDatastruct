#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<math.h>


#define INIT_STACK_SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;

typedef struct {
    ElemType *base;
    ElemType *top;
    int stackSize;
}seStack;

void initStack(seStack *s);
void push(seStack *s,ElemType e);
void pop(seStack *s,ElemType *e);
int stackLen(seStack s);

int main() {
seStack s2,s3;
    initStack(&s2);
    initStack(&s3);
    printf("请输入你想要转化的二进制数：输入'#'结束");
    ElemType c1;
    scanf("%c",&c1);
    while(c1 != '#')
    {
        push(&s2,c1);
        scanf("%c",&c1);
    }
    getchar();
    int i;
    if(stackLen(s2) % 3 == 0)
    {
        i = stackLen(s2)/3;
    } else
        i = stackLen(s2)/3 + 1;
    for(;i>0;i--)
    {
        ElemType mid = 0;
        ElemType rval;
        for(int j = 0;j<3;j++)
        {
            if(s2.base == s2.top)
            {
                rval = '0';
            }
           else
                pop(&s2,&rval);
            mid += (rval-48) * pow(2,j);
        }
        push(&s3,mid);
    }
    printf("转化后的八进制数是：");
    ElemType val;
    while (s3.top != s3.base)
    {
        pop(&s3,&val);
        printf("%d",val);
    }
    return 0;
}

void initStack(seStack *s)
{
    s->base = (ElemType *)malloc(sizeof(ElemType));
    if(!s->base)
        exit(0);
    s->top = s->base;
    s->stackSize = INIT_STACK_SIZE;
}

void push(seStack *s,ElemType e)
{
    if(s->top - s->base >= s->stackSize)
    {
        s->base = (ElemType *)realloc(s->base,(s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACKINCREMENT;
    }
    *(s->top) = e;
    s->top++;
}

void pop(seStack *s,ElemType *e)
{
    if(s->top == s->base)
        return;
    *e = *--(s->top);
}

int stackLen(seStack s)
{
    return (s.top - s.base);
}
