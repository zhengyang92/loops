#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int prev, int i, uint16_t * dest, int width, int use_pred, int fsym,
    int pix)
{
  for (i = 0; i < width; i++)
    {
      pix = fsym;
      if (use_pred)
	{
	  prev += pix;
	  prev &= 0x3FF;
	  pix = prev;
	}
      dest[i] = pix;
    }
}
