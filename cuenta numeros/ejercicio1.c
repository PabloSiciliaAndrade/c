#include <stdio.h>

int N, i, j;
int main(){
	scanf("%d ",&N );
	for (i = N; i > 0; --i)
	{
		for (j = 1; j <= N; ++j)
		{
			if (j <= i)
			{
				printf("%d",j );
			}
			else
			{
				printf(" ");
			}
		}
		for (j = N; j > 0; --j)
		{
			if (j > i)
			{
				printf(" ");
			}
			else
			{	
				printf("%d",j );
			}
		}
	printf("\n");
	}

	system("PAUSE");
	return 0;
}
