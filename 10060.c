#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * u_ptr, const uint8_t * a_ptr, const int a_stride, int values[3],
    int x, const int width, const int y_stride, uint8_t * v_ptr,
    uint8_t * y_ptr, const int uv_stride)
{
  int need_reset = 1;
  for (x = 0; x + 8 <= width; x += 8)
    {
      if (SmoothenBlock (a_ptr + x, a_stride, y_ptr + x, y_stride, 8, 8))
	{
	  if (need_reset)
	    {
	      values[0] = y_ptr[x];
	      values[1] = u_ptr[x >> 1];
	      values[2] = v_ptr[x >> 1];
	      need_reset = 0;
	    }
	  Flatten (y_ptr + x, values[0], y_stride, 8);
	  Flatten (u_ptr + (x >> 1), values[1], uv_stride, (8 / 2));
	  Flatten (v_ptr + (x >> 1), values[2], uv_stride, (8 / 2));
	}
      else
	{
	  need_reset = 1;
	}
    }
}
