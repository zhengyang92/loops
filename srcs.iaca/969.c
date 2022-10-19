#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, int offset, const uint16_t * msrc, int x, const uint16_t * asrc,
    int max, uint16_t * dst)
{
  for (x = 0; x < w; x++)
    {
      if (asrc[x] > 0 && asrc[x] < max)
	dst[x] =
	  ((((((msrc[x] - offset) >
	       (0) ? (msrc[x] - offset) : (0)) * (unsigned) max / asrc[x] +
	      offset) > (max) ? (max) : (((msrc[x] - offset) >
					  (0) ? (msrc[x] -
						 offset) : (0)) *
					 (unsigned) max / asrc[x] +
					 offset))) >
	   (0)
	   ? (((((msrc[x] - offset) >
		 (0) ? (msrc[x] - offset) : (0)) * (unsigned) max / asrc[x] +
		offset) > (max) ? (max) : (((msrc[x] - offset) >
					    (0) ? (msrc[x] -
						   offset) : (0)) *
					   (unsigned) max / asrc[x] +
					   offset))) : (0));
      else
	dst[x] = msrc[x];
    }
}
