#ifndef RLE_H
#define RLE_H

typedef struct pair {
  char c;
  int n;
} Pair;
typedef struct encoded {
  int length;
  Pair* arr;
} Encoded;

Encoded encode (char* text);
char* decode (Encoded text);

#endif
