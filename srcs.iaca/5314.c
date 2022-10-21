#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int x, ptrdiff_t stride, int y, uint8_t * dst)
{
  for (x = 0; x < 4; x++)
     { IACA_START
      uint8_t *p = dst + x * 4 + y * stride;
      do
	{
	  uint8_t SWAP_tmp = p[1];
	  p[1] = p[0];
	  p[0] = SWAP_tmp;
	}
      while (0);
     } IACA_END
}
