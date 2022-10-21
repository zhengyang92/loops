#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint16_t fixed_y_t;
typedef int16_t fixed_t;

int
fn (int i, int uv_w, fixed_t * dst, const fixed_y_t * src2,
    const fixed_y_t * src1)
{
  for (i = 0; i < uv_w; ++i)
     { IACA_START
      const int r =
	ScaleDown (src1[0 * uv_w + 0], src1[0 * uv_w + 1], src2[0 * uv_w + 0],
		   src2[0 * uv_w + 1]);
      const int g =
	ScaleDown (src1[2 * uv_w + 0], src1[2 * uv_w + 1], src2[2 * uv_w + 0],
		   src2[2 * uv_w + 1]);
      const int b =
	ScaleDown (src1[4 * uv_w + 0], src1[4 * uv_w + 1], src2[4 * uv_w + 0],
		   src2[4 * uv_w + 1]);
      const int W = RGBToGray (r, g, b);
      dst[0 * uv_w] = (fixed_t) (r - W);
      dst[1 * uv_w] = (fixed_t) (g - W);
      dst[2 * uv_w] = (fixed_t) (b - W);
      dst += 1;
      src1 += 2;
      src2 += 2;
} IACA_END }
