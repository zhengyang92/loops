#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int16_t int16_t;

int
fn (const unsigned int add, int16_t * srcu, int w, int i, int16_t * srcv,
    const unsigned int shift, uint16_t * dstv, uint16_t * dstu, int depth)
{
  for (i = 0; i < w; i++)
     { IACA_START
      dstu[i] = av_clip_uintp2_c (add + srcu[i], depth) << shift;
      dstv[i] = av_clip_uintp2_c (add + srcv[i], depth) << shift;
     } IACA_END
}
