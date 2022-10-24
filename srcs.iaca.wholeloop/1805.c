#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int scratch_linesize[4], int i, int32_t g, uint8_t * scratch_data[4],
    int32_t gg, int32_t bb, int32_t r, uint8_t * ir[2], int32_t b, int32_t rr)
{
  IACA_START for (i = 0; i < 4; ++i)
    {
      int i1, i2;
      i1 = (i & 1);
      i2 = (i >= 2);
      rr = ir[i2][i1 * 3 + 0];
      gg = ir[i2][i1 * 3 + 1];
      bb = ir[i2][i1 * 3 + 2];
      r += rr;
      g += gg;
      b += bb;
      rr = (2396625 * rr + 4793251 * gg + 1198732 * bb) >> 23;
      if (rr < 0)
	rr = 0;
      else if (rr > 255)
	rr = 255;
      scratch_data[0][i1 + i2 * scratch_linesize[0]] = rr;
     } IACA_END
}
