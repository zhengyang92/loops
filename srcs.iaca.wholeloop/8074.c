#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (const unsigned int add, int w, int16_t * srcu, int16_t * srcv, int i,
    const unsigned int shift, uint16_t * dstv, uint16_t * dstu, int depth)
{
  IACA_START for (i = 0; i < w; i++)
    {
      dstu[i] = av_clip_uintp2_c (add + srcu[i], depth) << shift;
      dstv[i] = av_clip_uintp2_c (add + srcv[i], depth) << shift;
     } IACA_END
}
