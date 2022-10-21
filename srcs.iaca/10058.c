#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int width, uint8_t * luma_ptr, int sum, const uint8_t * alpha_ptr)
{
  int count = 0;
  for (x = 0; x < width; ++x)
     { IACA_START
      if (alpha_ptr[x] != 0)
	{
	  ++count;
	  sum += luma_ptr[x];
	}
     } IACA_END
}
