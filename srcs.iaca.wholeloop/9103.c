#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int overflow, int from_y, int width, uint8_t * to, uint8_t * from,
    int height, int stride)
{
  IACA_START for (i = 0; i < height; i++)
    {
      memcpy (&to[i * stride + width], &from[(from_y + i) * stride],
	      overflow);
     } IACA_END
}
