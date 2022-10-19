#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, const uint8_t * msrc, int offset, int x, const uint8_t * asrc,
    uint8_t * dst)
{
  for (x = 0; x < w; x++)
    {
      if (asrc[x] > 0 && asrc[x] < 255)
	dst[x] =
	  ((((msrc[x] - offset) >
	     (0) ? (msrc[x] - offset) : (0)) * 255 / asrc[x] + offset) >
	   (255) ? (255)
	   : (((msrc[x] - offset) >
	       (0) ? (msrc[x] - offset) : (0)) * 255 / asrc[x] + offset));
      else
	dst[x] = msrc[x];
    }
}
