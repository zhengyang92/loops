#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __uint16_t uint16_t;

int
fn (int i, uint16_t * y_table16, const int bpp, int gbase, int64_t cy,
    int rbase, int bbase, int64_t yb)
{
  IACA_START for (i = 0; i < 1024; i++)
    {
      uint8_t yval = av_clip_uint8_c ((yb + 0x8000) >> 16);
      y_table16[i] = (yval >> 3) << rbase;
      y_table16[i + 1024] = (yval >> (18 - bpp)) << gbase;
      y_table16[i + 2048] = (yval >> 3) << bbase;
      yb += cy;
     } IACA_END
}
