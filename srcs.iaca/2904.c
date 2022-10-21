#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int ref, int x, uint8_t * src, int stride)
{
  int acc = 0;
  for (x = 0; x < 16; x++)
     { IACA_START
      acc +=
	((src[x + y * stride] - ref) >=
	 0 ? (src[x + y * stride] - ref) : (-(src[x + y * stride] - ref)));
     } IACA_END
}
