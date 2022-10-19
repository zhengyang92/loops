#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int y, const int qmul, int x, const int w, const int qadd, IDWTELEM * src,
    int stride)
{
  for (x = 0; x < w; x++)
    {
      int i = src[x + y * stride];
      if (i < 0)
	{
	  src[x + y * stride] = -((-i * qmul + qadd) >> ((7 - 4 + 8)));
	}
      else if (i > 0)
	{
	  src[x + y * stride] = ((i * qmul + qadd) >> ((7 - 4 + 8)));
	}
    }
}
