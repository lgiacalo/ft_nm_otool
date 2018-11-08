#include <stdio.h>

int main()
{
  int x = 1;

  char *y = (char*)&x;

  printf("%c\n",*y+48);
  printf("If 1 => Little Endian\nIf 0 => Big Endian\n");
}
