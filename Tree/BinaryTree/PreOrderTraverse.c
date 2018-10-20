#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild;//左子树
    struct BiTNode *rchild;//右子树
}BiTNode,*BiTree;

void createBiTree(BiTree *T);//创建一棵树
void PreOrderTraverse(BiTree T,int level);//前序遍历
void visit(char c,int level);//对节点的操作。这里是打印节点的值并输出层数

 void createBiTree(BiTree *T)   //？？？为什么这里要传入地址的地址？
{
    char c;
    scanf("%c",&c);
    if(' ' == c)  //如果输入的空格就将节点置空
    {
        *T = NULL;
    } else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = c;
        createBiTree(&(*T)->lchild);
        createBiTree(&(*T)->rchild);
    }
}


void PreOrderTraverse(BiTree T,int level)
{
    if(T)
    {
        visit(T->data,level);
        PreOrderTraverse(T->lchild,level + 1);
        PreOrderTraverse(T->rchild,level + 1);
    }
}


void visit(char c,int level)
{
    printf("%c位于第%d层\n",c,level);
}

int main() {
    int level = 1;
    BiTree T = NULL;
    createBiTree(&T);
    PreOrderTraverse(T,level);
    return 0;
}
