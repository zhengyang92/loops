#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int loc, int u[16][16], int v[16][16], int udif, int u0, int v0,
    int vdif)
{
  int j = 0;
  int ii = 0;
  int i = 0;
  for (int jj = 0; jj < 4; jj++)
     { IACA_START
      u[i + ii][j + jj] = u0 + ((udif * (int) (loc & 3) + 2) / 3);
      v[i + ii][j + jj] = v0 + ((vdif * (int) (loc & 3) + 2) / 3);
} IACA_END }
