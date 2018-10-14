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
    seStack s;
    initStack(&s);
    printf("请输入你想要转化的二进制数:(输入#结束)");
    char c;
    scanf("%c",&c);
    while (c != '#')
    {
        push(&s,c);
        scanf("%c",&c);
    }
    getchar();
    int len = stackLen(s);
    int decimal = 0;
    char val;
    for(int i = 0;i < len;i++)
    {
        pop(&s,&val);
        decimal += (val - 48) * pow(2,i);
    }
    printf("转化后的十进制数是：%d\n",decimal);
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
