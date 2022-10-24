#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *rbufferv, float *bufferv, float *bufferh, int j,
    const int block_size, float *rbufferh)
{
  IACA_START for (j = 0; j < block_size; j++)
    {
      bufferv[i * block_size + j] = bufferh[j * block_size + i];
      rbufferv[i * block_size + j] = rbufferh[j * block_size + i];
     } IACA_END
}
