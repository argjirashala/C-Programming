#include <stdio.h>
#include "rle.h"

int main() {
  char* text;
  scanf("%s",text);
  Encoded result=encode(text);
  for (int i = 0;i<result.length; i++) {
    printf("%c%d",result.arr[i].c, result.arr[i].n);
  }
  printf("->%s\n",decode(result));
  return 0;
}

