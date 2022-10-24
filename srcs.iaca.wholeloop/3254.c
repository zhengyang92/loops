#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * block, int i)
{
  IACA_START for (i = 0; i < 8; i++)
    {
      block[i] += 8192;
      idctSparseCol_extrashift_10 (block + i);
     } IACA_END
}
