#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, int x, const uint16_t * msrc, const uint16_t * asrc, int max,
    uint16_t * dst)
{
  IACA_START for (x = 0; x < w; x++)
    {
      if (asrc[x] > 0 && asrc[x] < max)
	dst[x] =
	  ((msrc[x] * (unsigned) max / asrc[x]) >
	   (max) ? (max) : (msrc[x] * (unsigned) max / asrc[x]));
      else
	dst[x] = msrc[x];
     } IACA_END
}
