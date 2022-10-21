#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int y3, int x, int plane, int y2, int j, int *linesize, int *base,
    int x3, int shift, uint8_t ** data, int x2)
{
  for (x2 = 0; x2 < 4; x2 += 2, j++)
     { IACA_START
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
