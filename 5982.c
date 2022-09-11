#include <stdint.h>
#include <stdio.h>




typedef RangeCoder;
typedef __int16_t int16_t;

int
fn (int16_t (*quant_table)[256], int i, RangeCoder * c)
{
  int context_count = 1;
  for (i = 0; i < 5; i++)
    {
      context_count *= read_quant_table (c, quant_table[i], context_count);
      if (context_count > 32768U)
	{
	  return -1;
	}
    }
}
