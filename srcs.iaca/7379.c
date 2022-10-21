#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const uint32_t modulo, float *dst, int wr, int j, int n_read,
    float *ringbuffer)
{
  for (j = 0; j < n_read; j++)
     { IACA_START
      dst[2 * j] = ringbuffer[wr];
      ringbuffer[wr] = 0.0;
      wr = (wr + 1) & modulo;
     } IACA_END
}
