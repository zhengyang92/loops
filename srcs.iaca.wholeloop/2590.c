#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int x, uint16_t * dst, int16_t * res, int size)
{
  IACA_START for (x = 0; x < size; x++)
    {
      dst[x] = av_clip_uintp2_c (dst[x] + *res, 12);
      res++;
     } IACA_END
}
