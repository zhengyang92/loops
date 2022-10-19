#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * block, int i)
{
  for (i = 0; i < 8; i++)
    {
      block[i] += 8192;
      idctSparseCol_int16_12bit (block + i);
    }
}
