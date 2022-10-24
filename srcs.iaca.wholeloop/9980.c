#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (const int last_pixel_pair, const uint8_t * cur_u, uint8_t * top_dst,
    uint32_t tl_uv, const uint8_t * top_u, uint32_t l_uv, int x,
    const uint8_t * bottom_y, uint8_t * bottom_dst, const uint8_t * cur_v,
    const uint8_t * top_y, const uint8_t * top_v)
{
  IACA_START for (x = 1; x <= last_pixel_pair; ++x)
    {
      const uint32_t t_uv = ((top_u[x]) | ((top_v[x]) << 16));
      const uint32_t uv = ((cur_u[x]) | ((cur_v[x]) << 16));
      const uint32_t avg = tl_uv + t_uv + l_uv + uv + 0x00080008u;
      const uint32_t diag_12 = (avg + 2 * (t_uv + l_uv)) >> 3;
      const uint32_t diag_03 = (avg + 2 * (tl_uv + uv)) >> 3;
      {
	const uint32_t uv0 = (diag_12 + tl_uv) >> 1;
	const uint32_t uv1 = (diag_03 + t_uv) >> 1;
	VP8YuvToRgb565 (top_y[2 * x - 1], uv0 & 0xff, (uv0 >> 16),
			top_dst + (2 * x - 1) * (2));
	VP8YuvToRgb565 (top_y[2 * x - 0], uv1 & 0xff, (uv1 >> 16),
			top_dst + (2 * x - 0) * (2));
      } if (bottom_y != ((void *) 0))
	{
	  const uint32_t uv0 = (diag_03 + l_uv) >> 1;
	  const uint32_t uv1 = (diag_12 + uv) >> 1;
	  VP8YuvToRgb565 (bottom_y[2 * x - 1], uv0 & 0xff, (uv0 >> 16),
			  bottom_dst + (2 * x - 1) * (2));
	  VP8YuvToRgb565 (bottom_y[2 * x + 0], uv1 & 0xff, (uv1 >> 16),
			  bottom_dst + (2 * x + 0) * (2));
	}
      tl_uv = t_uv;
      l_uv = uv;
}IACA_END}
