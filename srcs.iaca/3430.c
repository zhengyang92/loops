#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int prev, int i, int width, int use_pred, int fsym, int pix,
    uint8_t * dest)
{
  for (i = 0; i < width; i++)
    {
      pix = fsym;
      if (use_pred)
	{
	  prev += (unsigned) pix;
	  pix = prev;
	}
      dest[i] = pix;
}}
