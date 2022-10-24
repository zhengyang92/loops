#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __uint8_t uint8_t;
typedef __int32_t int32_t;

int
fn (unsigned int num, int32_t * dst, const uint16_t * const cf_table[16],
    unsigned int low, uint8_t * lut, int delta, BitstreamContext * bc,
    unsigned int sx, unsigned int high, unsigned int i, unsigned int value)
{
  IACA_START for (i = 0; i < num; i++)
    {
      unsigned int range = high - low + 1;
      unsigned int target = (((value - low + 1) << 14) - 1) / range;
      unsigned int symbol = lut[target >> (14 - (14 - 8))] << delta;
      while (cf_table[sx][symbol] > target)
	symbol += 1 << delta;
      symbol = (symbol >> delta) - 1;
      high =
	low + ((range * cf_table[sx][(symbol) << delta] - (1 << 14)) >> 14);
      low = low + ((range * cf_table[sx][(symbol + 1) << delta]) >> 14);
      while (1)
	{
	  if (high >= (2 * (((1 << 18) - 1) / 4 + 1)))
	    {
	      if (low >= (2 * (((1 << 18) - 1) / 4 + 1)))
		{
		  value -= (2 * (((1 << 18) - 1) / 4 + 1));
		  low -= (2 * (((1 << 18) - 1) / 4 + 1));
		  high -= (2 * (((1 << 18) - 1) / 4 + 1));
		}
	      else if (low >= (((1 << 18) - 1) / 4 + 1)
		       && high < (3 * (((1 << 18) - 1) / 4 + 1)))
		{
		  value -= (((1 << 18) - 1) / 4 + 1);
		  low -= (((1 << 18) - 1) / 4 + 1);
		  high -= (((1 << 18) - 1) / 4 + 1);
		}
	      else
		break;
	    }
	  low *= 2;
	  high = 2 * high + 1;
	  value = 2 * value + bitstream_read_bit (bc);
	}
      *dst++ = symbol;
     } IACA_END
}
