#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int i, int *dest, int c, const uint16_t * offsets, int k, int tmp,
    int shift, int group, const int *src)
{
  for (k = offsets[i]; k < offsets[i + 1]; k++)
    {
      tmp =
	(int) (((int64_t) src[group * 128 + k] * c +
		(int64_t) 0x1000000000) >> 37);
      dest[group * 128 + k] += tmp * (1U << shift);
}}
