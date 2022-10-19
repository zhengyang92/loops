#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int c1_shift_h, uint16_t * dst_data, const int dst_linesize,
    const int dst_signed_linesize, const int max, const uint16_t * c1_data,
    const uint16_t * c0_data, const int c1_linesize, const int mid, int x,
    const int c0_shift_w, const int c1_shift_w, int y, const int src_h,
    const int c0_shift_h, const int c0_linesize, const int limit,
    int intensity, uint16_t * dst)
{
  for (y = 0; y < src_h; y++)
    {
      const int sum =
	((((c0_data[x >> c0_shift_w] - mid) >=
	   0 ? (c0_data[x >> c0_shift_w] -
		mid) : (-(c0_data[x >> c0_shift_w] - mid))) +
	  ((c1_data[x >> c1_shift_w] - mid - 1) >=
	   0 ? (c1_data[x >> c1_shift_w] - mid -
		1) : (-(c1_data[x >> c1_shift_w] - mid - 1)))) >
	 (limit) ? (limit)
	 : (((c0_data[x >> c0_shift_w] - mid) >=
	     0 ? (c0_data[x >> c0_shift_w] -
		  mid) : (-(c0_data[x >> c0_shift_w] - mid))) +
	    ((c1_data[x >> c1_shift_w] - mid - 1) >=
	     0 ? (c1_data[x >> c1_shift_w] - mid -
		  1) : (-(c1_data[x >> c1_shift_w] - mid - 1)))));
      uint16_t *target;
      target = dst + x + dst_signed_linesize * sum;
      update16 (target, max, intensity, limit);
      if (!c0_shift_h || (y & c0_shift_h))
	c0_data += c0_linesize;
      if (!c1_shift_h || (y & c1_shift_h))
	c1_data += c1_linesize;
      dst_data += dst_linesize;
    }
}
