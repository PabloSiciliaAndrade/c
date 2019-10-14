#include <stdio.h>

int N, i, j;
int main(){
  scanf("%d ",&N );
  for (i = 1; i <= N; ++i)
  {
    for (j = N-i; j > 0; --j)
    {
      printf(" ");
    }
    for (j = i; j < (2*i); ++j)
    {
      printf("%d",j%10 );
    }
    for (j = 2*(i-1); j >= i; --j)
    {
      printf("%d",j%10 );
    }
  printf("\n");
  }

  system("PAUSE");
  return 0;
}
