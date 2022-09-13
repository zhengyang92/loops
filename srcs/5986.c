#include <stdint.h>
#include <stdio.h>




typedef RangeCoder;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t state[32], int16_t * quant_table, int i, RangeCoder * c)
{
  int last = 0;
  for (i = 1; i < 128; i++)
    if (quant_table[i] != quant_table[i - 1])
      {
	put_symbol (c, state, i - last - 1, 0);
	last = i;
      }
}
