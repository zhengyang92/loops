#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (const uint8_t * block, int y, int v_b, ptrdiff_t stride, int mind,
    int v_g, int x, const uint8_t * minp, int v_r, const uint8_t * maxp,
    int maxd)
{
  IACA_START for (x = 0; x < 4; x++)
    {
      int dot =
	block[x * 4 + y * stride + 0] * v_r + block[x * 4 + y * stride +
						    1] * v_g + block[x * 4 +
								     y *
								     stride +
								     2] * v_b;
      if (dot < mind)
	{
	  mind = dot;
	  minp = block + x * 4 + y * stride;
	}
      else if (dot > maxd)
	{
	  maxd = dot;
	  maxp = block + x * 4 + y * stride;
	}
     } IACA_END
}
