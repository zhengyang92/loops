#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int c1_shift_h, const int d0_signed_linesize,
    const uint8_t * c0_data, const int max, const int c1_linesize,
    uint8_t * d1_data, const int c0_shift_w, int x, const int c2_shift_h,
    const int c1_shift_w, int y, const uint8_t * c2_data, uint8_t * const d1,
    const int src_h, const int c2_shift_w, const int c0_shift_h,
    const int c2_linesize, const int c0_linesize, const uint8_t * c1_data,
    const int d1_signed_linesize, const int d0_linesize, uint8_t * d0_data,
    const int d1_linesize, int intensity, uint8_t * const d0)
{
  for (y = 0; y < src_h; y++)
    {
      const int c0 = c0_data[x >> c0_shift_w] + 256;
      const int c1 =
	((c1_data[x >> c1_shift_w] - 128) >=
	 0 ? (c1_data[x >> c1_shift_w] -
	      128) : (-(c1_data[x >> c1_shift_w] - 128))) +
	((c2_data[x >> c2_shift_w] - 128) >=
	 0 ? (c2_data[x >> c2_shift_w] -
	      128) : (-(c2_data[x >> c2_shift_w] - 128)));
      uint8_t *target;
      target = d0 + x + d0_signed_linesize * c0;
      update (target, max, intensity);
      target = d1 + x + d1_signed_linesize * (c0 - c1);
      update (target, max, intensity);
      target = d1 + x + d1_signed_linesize * (c0 + c1);
      update (target, max, intensity);
      if (!c0_shift_h || (y & c0_shift_h))
	c0_data += c0_linesize;
      if (!c1_shift_h || (y & c1_shift_h))
	c1_data += c1_linesize;
      if (!c2_shift_h || (y & c2_shift_h))
	c2_data += c2_linesize;
      d0_data += d0_linesize;
      d1_data += d1_linesize;
    }
}
