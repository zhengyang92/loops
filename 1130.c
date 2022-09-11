#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * d2_data, const uint8_t * c2_data, const uint8_t * c1_data,
    const int src_w, uint8_t * d1_data, int x, const int c0_shift_w,
    uint8_t * d0_data, const uint8_t * c0_data, const int c2_shift_w,
    const int c1_shift_w, const int max, const int intensity)
{
  for (x = 0; x < src_w; x++)
    {
      const int c0 = c0_data[x >> c0_shift_w] + 128;
      const int c1 = c1_data[x >> c1_shift_w] - 128;
      const int c2 = c2_data[x >> c2_shift_w] - 128;
      uint8_t *target;
      if (1)
	{
	  target = d0_data - c0;
	  update (target, max, intensity);
	  target = d1_data - (c0 + c1);
	  update (target, max, intensity);
	  target = d2_data - (c0 + c2);
	  update_cr (target, max, intensity);
	}
      else
	{
	  target = d0_data + c0;
	  update (target, max, intensity);
	  target = d1_data + (c0 + c1);
	  update (target, max, intensity);
	  target = d2_data + (c0 + c2);
	  update_cr (target, max, intensity);
	}
    }
}
