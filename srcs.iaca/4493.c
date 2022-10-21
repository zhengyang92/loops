#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * c0_data, const int mid, uint16_t * dst_data,
    const int src_w, int mirror, int x, const int c0_shift_w, const int limit,
    const int c1_shift_w, int intensity, const int max,
    const uint16_t * c1_data)
{
  for (x = 0; x < src_w; x++)
     { IACA_START
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
      if (mirror)
	{
	  target = dst_data - sum;
	  update16 (target, max, intensity, limit);
	}
      else
	{
	  target = dst_data + sum;
	  update16 (target, max, intensity, limit);
	}
     } IACA_END
}
