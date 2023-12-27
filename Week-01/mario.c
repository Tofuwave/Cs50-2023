#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int n;
  do
  {
    n = get_int("Height: ");

  }
  while (n < 1 || n > 8);

  for(int i = 0 ; i < n ; i++)

  {
  for(int j = i + 1; j < n ; j++)

  {
    printf(" ");
  }

  for(int k = i ; k + 1 ; k--)

  {
    printf("#");
  }


  for(int q = 1 ; q < 3 ; q++)

  {
    printf(" ");
  }

  for(int r = i ; r + 1 ; r--)

  {
   printf("#");
  }

  printf("\n");

  }

}