#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int v, int mask, int j, uint8_t * linear_to_xlaw)
{
  for (; j < v; j++)
    {
      linear_to_xlaw[8192 + j] = (i ^ mask);
      if (j > 0)
	linear_to_xlaw[8192 - j] = (i ^ (mask ^ 0x80));
    }
}
