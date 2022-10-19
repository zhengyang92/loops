#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * c1_data, const int src_w, int mirror,
    const int c0_shift_w, int x, const uint8_t * c0_data, uint8_t * dst_data,
    const int c1_shift_w, int intensity, const int max)
{
  for (x = 0; x < src_w; x++)
    {
      const int sum =
	((c0_data[x >> c0_shift_w] - 128) >=
	 0 ? (c0_data[x >> c0_shift_w] -
	      128) : (-(c0_data[x >> c0_shift_w] - 128))) +
	((c1_data[x >> c1_shift_w] - 127) >=
	 0 ? (c1_data[x >> c1_shift_w] -
	      127) : (-(c1_data[x >> c1_shift_w] - 127)));
      uint8_t *target;
      if (mirror)
	{
	  target = dst_data - sum;
	  update (target, max, intensity);
	}
      else
	{
	  target = dst_data + sum;
	  update (target, max, intensity);
	}
    }
}
