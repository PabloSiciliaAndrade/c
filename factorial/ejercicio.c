#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i, N, r = 1;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
	{
		r = i*r; 
	}
	printf("%d ",r);
    system("PAUSE");
	return 0;
}
