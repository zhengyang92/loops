#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int buffer_linesize, int i, const int nb_match_blocks, int k,
    float *bufferz, int j, const int block_size, float *buffer)
{
  for (k = 0; k < nb_match_blocks; k++)
     { IACA_START
      buffer[buffer_linesize * k + i * block_size + j] = bufferz[k];
     } IACA_END
}
