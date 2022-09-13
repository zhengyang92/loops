#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int w, int x, const int16_t (*filters)[8], int ioff, int dx, int imx,
    uint16_t * tmp_ptr, const uint16_t * src)
{
  for (x = 0; x < w; x++)
    {
      tmp_ptr[x] =
	av_clip_uintp2_c ((filters[imx][0] * src[ioff + -3 * 1] +
			   filters[imx][1] * src[ioff + -2 * 1] +
			   filters[imx][2] * src[ioff + -1 * 1] +
			   filters[imx][3] * src[ioff + +0 * 1] +
			   filters[imx][4] * src[ioff + +1 * 1] +
			   filters[imx][5] * src[ioff + +2 * 1] +
			   filters[imx][6] * src[ioff + +3 * 1] +
			   filters[imx][7] * src[ioff + +4 * 1] + 64) >> 7,
			  10);
      imx += dx;
      ioff += imx >> 4;
      imx &= 0xf;
    }
}
