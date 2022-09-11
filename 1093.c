#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * c2_data, const uint8_t * c1_data, const int src_w,
    uint8_t * d1_data, int mirror, int x, const int c0_shift_w,
    uint8_t * d0_data, const uint8_t * c0_data, const int c2_shift_w,
    const int c1_shift_w, int intensity, const int max)
{
  for (x = 0; x < src_w; x++)
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
      if (mirror)
	{
	  target = d0_data - c0;
	  update (target, max, intensity);
	  target = d1_data - (c0 - c1);
	  update (target, max, intensity);
	  target = d1_data - (c0 + c1);
	  update (target, max, intensity);
	}
      else
	{
	  target = d0_data + c0;
	  update (target, max, intensity);
	  target = d1_data + (c0 - c1);
	  update (target, max, intensity);
	  target = d1_data + (c0 + c1);
	  update (target, max, intensity);
	}
    }
}
