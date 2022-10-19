#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int *tmp, int i, uint8_t * dst)
{
  for (i = 0; i < 4; ++i)
    {
      const int dc = tmp[0] + 4;
      const int a = dc + tmp[8];
      const int b = dc - tmp[8];
      const int c =
	(((tmp[4]) * 35468) >> 16) - ((((tmp[12]) * 20091) >> 16) +
				      (tmp[12]));
      const int d =
	((((tmp[4]) * 20091) >> 16) + (tmp[4])) + (((tmp[12]) * 35468) >> 16);
      dst[(0) + (0) * 32] = clip_8b (dst[(0) + (0) * 32] + ((a + d) >> 3));
      dst[(1) + (0) * 32] = clip_8b (dst[(1) + (0) * 32] + ((b + c) >> 3));
      dst[(2) + (0) * 32] = clip_8b (dst[(2) + (0) * 32] + ((b - c) >> 3));
      dst[(3) + (0) * 32] = clip_8b (dst[(3) + (0) * 32] + ((a - d) >> 3));
      tmp++;
      dst += 32;
}}
