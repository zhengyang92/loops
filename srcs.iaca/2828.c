#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int mat[64], int size)
{
  int y = 0;
  for (int x = y + 1; x < size; x++)
     { IACA_START
      int a = mat[x * size + y];
      int b = mat[y * size + x];
      mat[y * size + x] = a;
      mat[x * size + y] = b;
} IACA_END }
