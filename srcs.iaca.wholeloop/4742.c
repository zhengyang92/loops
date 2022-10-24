#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (int y, int prev_dc, ptrdiff_t stride, int x, int width, int16_t * data)
{
  IACA_START for (x = 1; x < width - 1; x++)
    {
      int dc;
      dc = -prev_dc + data[x + y * stride] * 8 - data[x + 1 + y * stride];
      dc =
	(av_clip_c (dc, (-2147483647 - 1) / 10923, 2147483647 / 10923 - 32768)
	 * 10923 + 32768) >> 16;
      prev_dc = data[x + y * stride];
      data[x + y * stride] = dc;
}IACA_END}
