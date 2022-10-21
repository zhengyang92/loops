#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * block, int y, ptrdiff_t stride, int x, int mx, int mn)
{
  for (x = 0; x < 4; x++)
     { IACA_START
      int val = block[3 + x * 4 + y * stride];
      if (val < mn)
	mn = val;
      else if (val > mx)
	mx = val;
     } IACA_END
}
