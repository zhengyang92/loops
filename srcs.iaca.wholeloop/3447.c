#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int j, int width, uint8_t * val, GetBitContext * gb)
{
  IACA_START for (j = 0; j < width; j++)
    {
      if (val[j])
	{
	  int v = (1 << val[j]) + get_bits (gb, val[j]) - 1;
	  val[j] = (v >> 1) ^ -(v & 1);
	}
}IACA_END}
