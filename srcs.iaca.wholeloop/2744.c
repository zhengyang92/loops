#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int TL, int i, uint8_t * buf, int width, int L, int stride)
{
  IACA_START for (; i < width; i++)
    {
      L =
	mid_pred (L & 0xFF, buf[i - stride],
		  (L + buf[i - stride] - TL) & 0xFF) + buf[i];
      TL = buf[i - stride];
      buf[i] = L;
     } IACA_END
}
