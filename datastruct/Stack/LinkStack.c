#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *pNext;
}NODE,*PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK,*PSTACK;


void initStack(PSTACK pStack);
void push(PSTACK pStack,int val);
void traverse(PSTACK pStack);
bool isEmpty(PSTACK pStack);
bool pop(PSTACK pStack,int *val);
void clear(PSTACK pStack);
int stackLength(PSTACK pStack);

void getTop(PSTACK pStack);

int main() {
    STACK s;
    int val;
    int len;
    initStack(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    push(&s,6);
    push(&s,7);
    traverse(&s);
    getTop(&s);
    len = stackLength(&s);
    printf("栈的长度为：%d\n",len);
    if(pop(&s,&val))
    {
        printf("出栈成功！出栈的值为：%d\n",val);
    } else
        printf("出栈失败！\n");
    getTop(&s);
    len = stackLength(&s);
    printf("栈的长度为：%d\n",len);

    clear(&s);
    getTop(&s);
    len = stackLength(&s);
    printf("栈的长度为：%d\n",len);


    return 0;
}


void initStack(PSTACK pStack)
{
    pStack->pTop = (PNODE)malloc(sizeof(NODE));
    pStack->pBottom = pStack->pTop;
    pStack->pTop->pNext = NULL;
    return;
}

void push(PSTACK pStack,int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = pStack->pTop;
    pStack->pTop = pNew;
}

void traverse(PSTACK pStack)
{
    PNODE pTemp = pStack->pTop;
   if(isEmpty(pStack))
       printf("栈为空！\n");
   else
       while (pTemp != pStack->pBottom)
       {
           printf("%d  ",pTemp->data);
           pTemp = pTemp->pNext;
       }
    printf("\n");
    return;

}

bool isEmpty(PSTACK pStack)
{
    if(pStack->pTop == pStack->pBottom)
        return true;
    else
        return false;
}

bool pop(PSTACK pStack,int *val)
{
    if(isEmpty(pStack))
    {
        return false;
    }


    else
    {
        PNODE  p = pStack->pTop;
        *val = p->data;
        pStack->pTop = p->pNext;
        free(p);
        p = NULL;
        return true;

    }
}

void clear(PSTACK pStack)
{
    if(isEmpty(pStack))
    {
        return;
    } else {
        PNODE p = pStack->pTop;
        PNODE q;
        while (p != pStack->pBottom)
        {
            q = p->pNext;
            free(p);
            p = q;
        }
        pStack->pTop = pStack->pBottom;
        return;
    }
}

int stackLength(PSTACK pStack)
{
    PNODE p = pStack->pTop;
    int len = 0;
    if(isEmpty(pStack))
        return len;
    else
    {
        while(p != pStack->pBottom)
        {
            p = p->pNext;
            len++;
        }
        return len;
    }
}

void getTop(PSTACK pStack)
{
    if(isEmpty(pStack))
    {
        printf("栈为空！栈顶元素不存在！\n");
        return ;
    } else
    printf("栈顶元素为：%d\n",pStack->pTop->data);
}
