#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int w, int x, const int16_t (*filters)[8], int ioff, int dx,
    const uint8_t * src, uint8_t * tmp_ptr, int imx)
{
  IACA_START for (x = 0; x < w; x++)
    {
      tmp_ptr[x] =
	av_clip_uint8_c ((filters[imx][0] * src[ioff + -3 * 1] +
			  filters[imx][1] * src[ioff + -2 * 1] +
			  filters[imx][2] * src[ioff + -1 * 1] +
			  filters[imx][3] * src[ioff + +0 * 1] +
			  filters[imx][4] * src[ioff + +1 * 1] +
			  filters[imx][5] * src[ioff + +2 * 1] +
			  filters[imx][6] * src[ioff + +3 * 1] +
			  filters[imx][7] * src[ioff + +4 * 1] + 64) >> 7);
      imx += dx;
      ioff += imx >> 4;
      imx &= 0xf;
     } IACA_END
}
