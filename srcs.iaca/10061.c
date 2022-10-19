#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int x, int w, uint32_t * argb)
{
  for (x = 0; x < w; ++x)
    {
      if ((argb[x] & 0xff000000) == 0)
	{
	  argb[x] = 0x00000000;
	}
    }
}
