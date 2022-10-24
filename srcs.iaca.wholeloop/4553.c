#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int i, int *dest, int round, int c, int k, const uint16_t * offsets,
    int tmp, int shift, int group, const int *src)
{
  IACA_START for (k = offsets[i]; k < offsets[i + 1]; k++)
    {
      tmp =
	(int) (((int64_t) src[group * 128 + k] * c +
		(int64_t) 0x1000000000) >> 37);
      dest[group * 128 + k] += (tmp + (int64_t) round) >> shift;
}IACA_END}
