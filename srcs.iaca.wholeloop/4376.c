#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int32_t int32_t;

int
fn (const int fill_color, int i, uint16_t * out, const int w,
    const uint16_t * indata, const int off_y, const int inlinesize,
    const int xcenter, const int ycenter, const int h,
    const int32_t * correction)
{
  IACA_START for (int j = 0; j < w; j++)
    {
      const int off_x = j - xcenter;
      const int64_t radius_mult = correction[j + i * w];
      const int x = xcenter + ((radius_mult * off_x + (1 << 23)) >> 24);
      const int y = ycenter + ((radius_mult * off_y + (1 << 23)) >> 24);
      const char isvalid = x >= 0 && x < w && y >= 0 && y < h;
      *out++ = isvalid ? indata[y * inlinesize + x] : fill_color;
}IACA_END}
