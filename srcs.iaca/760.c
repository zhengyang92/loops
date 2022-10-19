#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int x_start, const int x_end, void *log_ctx, const double d, int x,
    int nbits, const double a, const double c, const int scale,
    const double b, uint16_t * y)
{
  for (x = x_start; x <= x_end; x++)
    {
      const double xx = (x - x_start) * 1. / scale;
      const double yy = a + b * xx + c * xx * xx + d * xx * xx * xx;
      y[x] =
	(nbits ==
	 8 ? av_clip_uint8_c (yy * scale) : av_clip_uintp2_c (yy * scale,
							      nbits));
      av_log (log_ctx, 48, "f(%f)=%f -> y[%d]=%d\n", xx, yy, x, y[x]);
}}
