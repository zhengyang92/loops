#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int signs[22], int i, int t)
{
  for (j = 0; j < 11; j++)
    {
      signs[i * 11 + j] = ((t & 1) * 2 - 1) * (1 << 14);
      t >>= 1;
    }
}
