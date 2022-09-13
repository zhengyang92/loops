#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (const uint32_t * const argb, int used_subtract_green, uint32_t right,
    int x, int width, uint32_t left, uint32_t down, uint32_t up,
    uint8_t * const max_diffs, uint32_t current, int stride)
{
  for (x = 1; x < width - 1; ++x)
    {
      up = argb[-stride + x];
      down = argb[stride + x];
      left = current;
      current = right;
      right = argb[x + 1];
      if (used_subtract_green)
	{
	  up = AddGreenToBlueAndRed (up);
	  down = AddGreenToBlueAndRed (down);
	  right = AddGreenToBlueAndRed (right);
	}
      max_diffs[x] = MaxDiffAroundPixel (current, up, down, left, right);
    }
}
