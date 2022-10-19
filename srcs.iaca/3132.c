#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int p, int width, int code, uint8_t * dst, int height, int stride)
{
  int filled = 0;
  for (i = 0; i <= code; i++)
    {
      dst[filled++] = p;
      if (filled >= width)
	{
	  filled = 0;
	  dst -= stride;
	  height--;
	  if (height < 0)
	    break;
	}
    }
}
