#include <stdint.h>
#include <stdio.h>




typedef RangeCoder;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int16_t * quant_table, int i, uint8_t state[32], RangeCoder * c)
{
  int last = 0;
  for (i = 1; i < 128; i++)
    if (quant_table[i] != quant_table[i - 1])
      {
	put_symbol (c, state, i - last - 1, 0);
	last = i;
      }
}
