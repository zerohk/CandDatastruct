#include<stdio.h> 


int main(void)
{
	char ch = 'F';
	for(int i=1;i<=6;i++)
		{
			for(int j=1;j<=i;j++)
			{
				printf("%c",ch--);
			}
			ch='F';
				
			printf("\n");
		}
	
	return 0;
}



/***
F
FE
FED
FEDC
FEDCB
FEDCBA
***/
