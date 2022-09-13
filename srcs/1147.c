#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * d1_data, const uint16_t * c0_data, const uint16_t * c2_data,
    const int src_w, int mirror, int x, uint16_t * d2_data,
    const int c0_shift_w, const int limit, const int c2_shift_w,
    uint16_t * d0_data, const int c1_shift_w, int intensity, const int max,
    const uint16_t * c1_data)
{
  for (x = 0; x < src_w; x++)
    {
      const int c0 =
	((c0_data[x >> c0_shift_w]) >
	 (limit) ? (limit) : (c0_data[x >> c0_shift_w]));
      const int c1 = c1_data[x >> c1_shift_w];
      const int c2 = c2_data[x >> c2_shift_w];
      if (mirror)
	{
	  update16 (d0_data - c0, max, intensity, limit);
	  *(d1_data - c0) = c1;
	  *(d2_data - c0) = c2;
	}
      else
	{
	  update16 (d0_data + c0, max, intensity, limit);
	  *(d1_data + c0) = c1;
	  *(d2_data + c0) = c2;
	}
    }
}
