#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint64_t uint64_t;

int
fn (int pixel, uint64_t idx, uint8_t octet[8])
{
  for (int w = 0; w < 8; w++)
     { IACA_START
      if (octet[w] == pixel)
	{
	  idx = w;
	  break;
	}
     } IACA_END
}
