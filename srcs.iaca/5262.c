#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (int pixel, uint32_t idx, uint8_t quad[4])
{
  for (int w = 0; w < 4; w++)
     { IACA_START
      if (quad[w] == pixel)
	{
	  idx = w;
	  break;
	}
     } IACA_END
}
