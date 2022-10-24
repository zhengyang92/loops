#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __int32_t int32_t;

int
fn (int32_t * current_res, unsigned int cur_s, unsigned int sx[8],
    BitstreamContext * bc, int delta[8], unsigned int sb_length,
    unsigned int cur_tail_code, unsigned int cur_k, unsigned int start,
    int sb)
{
  IACA_START for (; start < sb_length; start++)
    {
      int32_t res = *current_res;
      if (res == cur_tail_code)
	{
	  unsigned int max_msb =
	    (2 + (sx[sb] > 2) + (sx[sb] > 10)) << (5 - delta[sb]);
	  res = decode_rice (bc, cur_s);
	  if (res >= 0)
	    {
	      res += (max_msb) << cur_k;
	    }
	  else
	    {
	      res -= (max_msb - 1) << cur_k;
	    }
	}
      else
	{
	  if (res > cur_tail_code)
	    res--;
	  if (res & 1)
	    res = -res;
	  res >>= 1;
	  if (cur_k)
	    {
	      res <<= cur_k;
	      res |= bitstream_read (bc, cur_k);
	    }
	}
      *current_res++ = res;
     } IACA_END
}
