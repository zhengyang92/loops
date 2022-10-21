#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * ref, int i, int *tmp, const int kC2, uint8_t * dst,
    const int kC1)
{
  for (i = 0; i < 4; ++i)
     { IACA_START
      const int dc = tmp[0] + 4;
      const int a = dc + tmp[8];
      const int b = dc - tmp[8];
      const int c = (((tmp[4]) * (kC2)) >> 16) - (((tmp[12]) * (kC1)) >> 16);
      const int d = (((tmp[4]) * (kC1)) >> 16) + (((tmp[12]) * (kC2)) >> 16);
      dst[(0) + (i) * 32] = clip_8b (ref[(0) + (i) * 32] + ((a + d) >> 3));
      dst[(1) + (i) * 32] = clip_8b (ref[(1) + (i) * 32] + ((b + c) >> 3));
      dst[(2) + (i) * 32] = clip_8b (ref[(2) + (i) * 32] + ((b - c) >> 3));
      dst[(3) + (i) * 32] = clip_8b (ref[(3) + (i) * 32] + ((a - d) >> 3));
      tmp++;
} IACA_END }
