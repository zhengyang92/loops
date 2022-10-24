#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, uint16_t * dst, int x, uint16_t * tmp_ptr, int avg, int my)
{
  IACA_START for (x = 0; x < w; x++)
    if (avg)
      {
	dst[x] =
	  (dst[x] +
	   (tmp_ptr[x] + ((my * (tmp_ptr[x + 64] - tmp_ptr[x]) + 8) >> 4)) +
	   1) >> 1;
      }
    else
      {
	dst[x] =
	  (tmp_ptr[x] + ((my * (tmp_ptr[x + 64] - tmp_ptr[x]) + 8) >> 4));
      }
}
