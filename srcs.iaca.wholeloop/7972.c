#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int mv, const uint8_t ff_mvtab[33][2], int f_code,
    uint8_t mv_penalty[8][16385])
{
  IACA_START for (mv = -(2 * 4096); mv <= (2 * 4096); mv++)
    {
      int len;
      if (mv == 0)
	len = ff_mvtab[0][1];
      else
	{
	  int val, bit_size, code;
	  bit_size = f_code - 1;
	  val = mv;
	  if (val < 0)
	    val = -val;
	  val--;
	  code = (val >> bit_size) + 1;
	  if (code < 33)
	    {
	      len = ff_mvtab[code][1] + 1 + bit_size;
	    }
	  else
	    {
	      len =
		ff_mvtab[32][1] + (31 - __builtin_clz ((code >> 5) | 1)) + 2 +
		bit_size;
	    }
	}
      mv_penalty[f_code][mv + (2 * 4096)] = len;
     } IACA_END
}
