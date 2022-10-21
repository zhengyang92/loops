#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * d1_data, const uint16_t * c0_data, const uint16_t * c2_data,
    const int mid, const int src_w, uint16_t * d2_data, const int c0_shift_w,
    int x, const int limit, const int c2_shift_w, uint16_t * d0_data,
    const int c1_shift_w, const uint16_t * c1_data, const int max,
    const int intensity)
{
  for (x = 0; x < src_w; x++)
     { IACA_START
      const int c0 =
	((c0_data[x >> c0_shift_w]) >
	 (limit) ? (limit) : (c0_data[x >> c0_shift_w])) + mid;
      const int c1 =
	((c1_data[x >> c1_shift_w]) >
	 (limit) ? (limit) : (c1_data[x >> c1_shift_w])) - mid;
      const int c2 =
	((c2_data[x >> c2_shift_w]) >
	 (limit) ? (limit) : (c2_data[x >> c2_shift_w])) - mid;
      uint16_t *target;
      if (0)
	{
	  target = d0_data - c0;
	  update16 (target, max, intensity, limit);
	  target = d1_data - (c0 + c1);
	  update16_cr (target, max, intensity, limit);
	  target = d2_data - (c0 + c2);
	  update16_cr (target, max, intensity, limit);
	}
      else
	{
	  target = d0_data + c0;
	  update16 (target, max, intensity, limit);
	  target = d1_data + (c0 + c1);
	  update16_cr (target, max, intensity, limit);
	  target = d2_data + (c0 + c2);
	  update16_cr (target, max, intensity, limit);
	}
     } IACA_END
}
