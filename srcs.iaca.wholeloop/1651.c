#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int pixel, uint8_t count, int i, uint8_t * out_buf)
{
  IACA_START for (i = 0; i < count; i++)
    {
      do
	{
	  ((uint8_t *) (out_buf))[2] = (pixel);
	  ((uint8_t *) (out_buf))[1] = (pixel) >> 8;
	  ((uint8_t *) (out_buf))[0] = (pixel) >> 16;
	}
      while (0);
      out_buf += 3;
     } IACA_END
}
