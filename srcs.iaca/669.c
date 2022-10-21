#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *bufferv, float *bufferh, int j, const int block_size)
{
  for (j = 0; j < block_size; j++)
     { IACA_START
      bufferh[j * block_size + i] = bufferv[i * block_size + j];
     } IACA_END
}
