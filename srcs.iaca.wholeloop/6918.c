#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t stride, int x, uint8_t * dst, int y)
{
  IACA_START for (x = 0; x < 4; x++)
    {
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
