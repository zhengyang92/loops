#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * d2_data, const uint8_t * c2_data, const uint8_t * c1_data,
    uint8_t * d1_data, const int src_w, int mirror, int x,
    const int c0_shift_w, uint8_t * d0_data, const uint8_t * c0_data,
    const int c2_shift_w, const int c1_shift_w, int intensity, const int max)
{
  IACA_START for (x = 0; x < src_w; x++)
    {
      const int c0 = c0_data[x >> c0_shift_w];
      const int c1 = c1_data[x >> c1_shift_w];
      const int c2 = c2_data[x >> c2_shift_w];
      if (mirror)
	{
	  update (d0_data - c0, max, intensity);
	  *(d1_data - c0) = c1;
	  *(d2_data - c0) = c2;
	}
      else
	{
	  update (d0_data + c0, max, intensity);
	  *(d1_data + c0) = c1;
	  *(d2_data + c0) = c2;
	}
     } IACA_END
}
