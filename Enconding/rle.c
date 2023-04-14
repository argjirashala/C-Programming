#include <stdio.h>
#include <string.h>

typedef struct pair {
  char c;
  int n;
} Pair;
typedef struct encoded {
  int length;
  Pair* arr;
} Encoded;

char* decode (Encoded text) {
  char* result;
  int length =0;
  for (int i =0; i<text.length; i++) {
    for (int j=0;j<text.arr[i].n; j++) {
      result[length]=text.arr[i].c;
      length++;
    }
  }
  return result;
}


Encoded encode (char* text) {
  char t=text[0];
  int r= 1,length=0;
  static Pair result[255];
  for (unsigned long i = 1;i<strlen(text);i++) {
        t=text[i];
    if (t==text[i-1]) {
      r++;
    }
    else {
      result[length].c=text[i-1];
      result[length].n=r;
      r=1;
      length++;
    }
    if (i+1==strlen(text)) {
      result[length].c=text[i-1];
      result[length].n=r;
      length++;
    }
  }
  Encoded theresult;
  theresult.length=length;
  theresult.arr=result;
  return theresult;
}

