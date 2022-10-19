#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w0, int x, unsigned int *cchange, const uint8_t * in0, uint8_t * dst)
{
  for (x = 0; x < w0; x++)
    {
      dst[x] = av_clip_uint8_c (cchange[in0[x]]);
    }
}
