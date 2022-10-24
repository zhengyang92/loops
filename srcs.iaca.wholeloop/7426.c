#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int64_t int64_t;

int
fn (const int area, const int width, int64_t sum, const int size_w,
    int64_t * col_sum, uint16_t * dst)
{
  IACA_START for (int x = 1; x < width; x++)
    {
      sum = sum - col_sum[x - size_w - 1] + col_sum[x + size_w];
      ((void) 0);
      dst[x] = ((sum) / (area));
}IACA_END}
