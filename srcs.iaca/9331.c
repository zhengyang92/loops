#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int x, uint16_t * dst, int16_t * res, int size)
{
  for (x = 0; x < size; x++)
     { IACA_START
      dst[x] = av_clip_uintp2_c (dst[x] + *res, 9);
      res++;
     } IACA_END
}
