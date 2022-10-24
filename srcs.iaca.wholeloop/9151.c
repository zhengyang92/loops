#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int y3, uint8_t ** data, int x, int plane, int j, int y2,
    int *linesize, int *base, int x3, int shift, int x2)
{
  IACA_START for (x2 = 0; x2 < 4; x2 += 2, j++)
    {
      plane = y2 < 4 ? 0 : 1 + (x2 >> 1);
      shift = y2 < 4 ? 0 : 1;
      x3 = shift ? 0 : x2;
      y3 = shift ? 0 : y2;
      base[j] =
	(data[plane]
	 [((x + x3) >> shift) + ((y + y3) >> shift) * linesize[plane]] +
	 data[plane][((x + x3) >> shift) + 1 +
		     ((y + y3) >> shift) * linesize[plane]] +
	 data[plane][((x + x3) >> shift) +
		     (((y + y3) >> shift) + 1) * linesize[plane]] +
	 data[plane][((x + x3) >> shift) + 1 +
		     (((y + y3) >> shift) + 1) * linesize[plane]]) >> 2;
     } IACA_END
}
