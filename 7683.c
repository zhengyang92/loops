#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __int32_t int32_t;

int
fn (unsigned int cur_s, int32_t * current_res, unsigned int sx[8],
    int delta[8], unsigned int sb_length, unsigned int cur_tail_code,
    GetBitContext * gb, unsigned int start, int sb, unsigned int cur_k)
{
  for (; start < sb_length; start++)
    {
      int32_t res = *current_res;
      if (res == cur_tail_code)
	{
	  unsigned int max_msb =
	    (2 + (sx[sb] > 2) + (sx[sb] > 10)) << (5 - delta[sb]);
	  res = decode_rice (gb, cur_s);
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
	      res *= 1U << cur_k;
	      res |= get_bits_long (gb, cur_k);
	    }
	}
      *current_res++ = res;
    }
}
