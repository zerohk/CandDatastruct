#include <stdio.h>

char get_choice(void);
void count(void);
char get_first(void);

int main(void) {

    int choice;
    while ((choice = get_choice() ) != 'q')
    {
        switch (choice)
        {
            case 'a':
                printf("Buy now,sell high\n");
                break;
            case 'b':
                printf("\a");
                break;
            case 'c':
                count();
            default:
                printf("System error");
                break;
        }
    }

    return 0;
}

char get_choice(void)
{
    int ch;
    printf("Enter the letter of ur choice:\n");
    printf("a:advice    b:bell\n");
    printf("c:count     q:exit\n");
    ch = get_first();
    while (ch < 'a' || ch > 'c' && ch != 'q')
    {
        printf("Please respond with a,b,c or q\n");
        ch = get_first();
    }
    return ch;

}

char get_first(void)
{
    int ch;
    ch = getchar();
    while ( ch == ' ' || ch == '\n')
        ch = getchar();
    while(getchar() != '\n')
        continue;
    return ch;

}

void count(void)
{
    int n,i;

    printf("Count how far? Enter an integer:\n");
    scanf("%d",&n);
    for(i = 1;i <= n;i++)
        printf("%d\n",i);
}

