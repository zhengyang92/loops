#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (const int width, const int size_w, int32_t * col_sum, uint8_t * dst,
    const uint16_t * lut)
{
  int32_t sum = 0;
  IACA_START for (int x = 1; x < width; x++)
    {
      sum = sum - col_sum[x - size_w - 1] + col_sum[x + size_w];
      ((void) 0);
      dst[x] = (lut[(sum)]);
}IACA_END}
