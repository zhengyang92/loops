#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef RangeCoder;
typedef __int16_t int16_t;

int
fn (int16_t (*quant_table)[256], int i, RangeCoder * c)
{
  int context_count = 1;
  for (i = 0; i < 5; i++)
     { IACA_START
      int ret = read_quant_table (c, quant_table[i], context_count);
      if (ret < 0)
	return ret;
      context_count *= ret;
      if (context_count > 32768U)
	{
	  return (-(int)
		  (('I') | (('N') << 8) | (('D') << 16) |
		   ((unsigned) ('A') << 24)));
	}
} IACA_END }
