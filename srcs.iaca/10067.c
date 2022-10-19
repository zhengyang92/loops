#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (int exact, int y, uint32_t * current_row, uint32_t * const modes,
    uint32_t * upper_row, int bits, int used_subtract_green,
    uint32_t * const argb, int width, int x, int max_quantization,
    const int tiles_per_row, uint8_t * current_max_diffs, int height)
{
  for (x = 0; x < width;)
    {
      const int mode =
	(modes[(y >> bits) * tiles_per_row + (x >> bits)] >> 8) & 0xff;
      int x_end = x + (1 << bits);
      if (x_end > width)
	x_end = width;
      GetResidual (width, height, upper_row, current_row, current_max_diffs,
		   mode, x, x_end, y, max_quantization, exact,
		   used_subtract_green, argb + y * width + x);
      x = x_end;
    }
}
