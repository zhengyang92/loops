#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * distinct_values, const uint8_t * block_values, int size)
{
  int n = 1;
  for (int i = 1; i < size; i++)
     { IACA_START
      if (block_values[i] != block_values[i - 1])
	{
	  distinct_values[n] = block_values[i];
	  n++;
	}
     } IACA_END
}
