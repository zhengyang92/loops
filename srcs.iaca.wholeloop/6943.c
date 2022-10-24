#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int prev, int i, int width, int use_pred, int fsym, int pix, int step,
    uint8_t * dest)
{
  IACA_START for (i = 0; i < width * step; i += step)
    {
      pix = fsym;
      if (use_pred)
	{
	  prev += pix;
	  pix = prev;
	}
      dest[i] = pix;
     } IACA_END
}
