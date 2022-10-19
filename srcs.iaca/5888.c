#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __uint32_t uint32_t;

int
fn (int i, char bits[65], BitstreamContext * bc, uint32_t v, unsigned int k,
    int j)
{
  for (j = 0; j < i; j++)
    {
      k = bitstream_read_bit (bc);
      bits[i + j + 1] = k ? '1' : '0';
      v = v << 1 | k;
    }
}
