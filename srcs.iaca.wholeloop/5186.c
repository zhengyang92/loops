#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef __uint8_t uint8_t;

int
fn (size_t b, uint8_t * foreground, uint8_t foreground_alpha,
    const uint8_t * background, const int bpp, uint8_t output[10],
    uint8_t output_alpha, uint8_t background_alpha)
{
  IACA_START for (b = 0; b < bpp - 1; ++b)
    {
      if (output_alpha == 0)
	{
	  output[b] = 0;
	}
      else if (background_alpha == 255)
	{
	  output[b] =
	    ((((foreground_alpha * foreground[b] +
		(255 - foreground_alpha) * background[b]) +
	       128) * 257) >> 16);
	}
      else
	{
	  output[b] =
	    (255 * foreground_alpha * foreground[b] +
	     (255 -
	      foreground_alpha) * background_alpha * background[b]) / (255 *
								       output_alpha);
	}
     } IACA_END
}
