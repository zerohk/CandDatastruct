//
// Created by zerohk on 2018/10/17.
//

/*利用递归倒序输出输入的任意字符串
 *
 */

#include <stdio.h>

void reversePrint();

int main(void)
{
    reversePrint();
    return 0;
}

void reversePrint()
{
    char c ;
    scanf("%c",&c);
    if(c != '#') reversePrint();
    if(c != '#') printf("%c",c);
}
