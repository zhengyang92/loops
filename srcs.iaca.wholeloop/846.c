#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int height, const float *src, int i, int row, const int src_stride,
    const int width, float temp, const int radius)
{
  int j = 0;
  IACA_START for (int col = -radius; col <= radius; col++)
    {
      int x = i + row;
      int y = j + col;
      x = (x < 0) ? 0 : (x >= height ? height - 1 : x);
      y = (y < 0) ? 0 : (y >= width ? width - 1 : y);
      temp += src[x * src_stride + y];
}IACA_END}
