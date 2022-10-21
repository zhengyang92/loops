#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (const uint8_t x_offset[2], int i, int temp[8], int16_t * block, int qmul,
    const int stride)
{
  for (i = 0; i < 2; i++)
     { IACA_START
      const int offset = x_offset[i];
      const int z0 = temp[2 * 0 + i] + temp[2 * 2 + i];
      const int z1 = temp[2 * 0 + i] - temp[2 * 2 + i];
      const int z2 = temp[2 * 1 + i] - temp[2 * 3 + i];
      const int z3 = temp[2 * 1 + i] + temp[2 * 3 + i];
      block[stride * 0 + offset] = ((z0 + z3) * qmul + 128) >> 8;
      block[stride * 1 + offset] = ((z1 + z2) * qmul + 128) >> 8;
      block[stride * 2 + offset] = ((z1 - z2) * qmul + 128) >> 8;
      block[stride * 3 + offset] = ((z0 - z3) * qmul + 128) >> 8;
} IACA_END }
