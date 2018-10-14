#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10
#define MAXBUFFER       10

typedef double ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

void InitStack(sqStack *s);
void Push(sqStack *s, ElemType e);
void Pop(sqStack *s, ElemType *e);
ElemType count(ElemType c1,ElemType c2,ElemType c);


void InitStack(sqStack *s)
{
s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
if( !s->base )
exit(0);

s->top = s->base;
s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s, ElemType e)
{
// 栈满，追加空间，鱼油必须懂！
if( s->top - s->base >= s->stackSize )
{
s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
if( !s->base )
exit(0);

s->top = s->base + s->stackSize;
s->stackSize = s->stackSize + STACKINCREMENT;
}

*(s->top) = e;      // 存放数据
s->top++;
}

void Pop(sqStack *s, ElemType *e)
{
if( s->top == s->base )
return;

*e = *--(s->top);   // 将栈顶元素弹出并修改栈顶指针
}

int StackLen(sqStack s)
{
    return (s.top - s.base);
}

ElemType count(ElemType c1,ElemType c2,ElemType c)
{
    if(c == '+')
    {
        return c1 + c2;
    } else
        if(c == '-')
            return c1 - c2;
        else
            if(c == '*')
                return c1 * c2;
            else
                return c1 / c2;
}

int main()
{
    sqStack s;
    InitStack(&s);
    // 亲爱的鱼油，请从此处开始写代码！
    printf("请输入逆波兰表达式：");
    char c;
    double d,e;
    int i = 0;
    scanf("%c",&c);
    char string[MAXBUFFER];
    while (c != '#')
    {
        while (isdigit(c) || c == '.')//过滤数字
        {
            string[i++] = c;
            string[i] = '\0';
            if(i >= 10)
                printf("\n出错，输入的单个数字过大！\n");
            scanf("%c",&c);
            if(c == ' ')
            {
                d = atof(string);
                Push(&s,d);
                i = 0;
                break;
            }
        }
        switch (c)
        {
            case '+':
                Pop(&s,&e);
                Pop(&s,&d);
                Push(&s,d + e);
                break;
            case '-':
                Pop(&s,&e);
                Pop(&s,&d);
                Push(&s,d - e);
                break;
            case '*':
                Pop(&s,&e);
                Pop(&s,&d);
                Push(&s,d * e);
                break;
            case '/':
                Pop(&s,&e);
                Pop(&s,&d);
                if(e == 0)
                    printf("\n错误，除数为零\n");
                else
                    Push(&s,d / e);
                break;
        }
        scanf("%c",&c);
    }
printf("\n计算后的结果是：");
        Pop(&s,&e);
        printf("%f",e);

    return 0;
}
