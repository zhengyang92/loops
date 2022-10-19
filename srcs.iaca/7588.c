#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int c1_shift_h, int y, const int c1_linesize,
    const uint8_t * c1_data, const int dst_linesize, int x,
    const int c0_shift_w, const uint8_t * c0_data, const int src_h,
    const int dst_signed_linesize, uint8_t * dst_data, const int c0_shift_h,
    const int c1_shift_w, const int c0_linesize, int intensity, const int max,
    uint8_t * dst)
{
  for (y = 0; y < src_h; y++)
    {
      const int sum =
	((c0_data[x >> c0_shift_w] - 128) >=
	 0 ? (c0_data[x >> c0_shift_w] -
	      128) : (-(c0_data[x >> c0_shift_w] - 128))) +
	((c1_data[x >> c1_shift_w] - 127) >=
	 0 ? (c1_data[x >> c1_shift_w] -
	      127) : (-(c1_data[x >> c1_shift_w] - 127)));
      uint8_t *target;
      target = dst + x + dst_signed_linesize * sum;
      update (target, max, intensity);
      if (!c0_shift_h || (y & c0_shift_h))
	c0_data += c0_linesize;
      if (!c1_shift_h || (y & c1_shift_h))
	c1_data += c1_linesize;
      dst_data += dst_linesize;
    }
}
