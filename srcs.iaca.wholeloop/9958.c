#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t * argb_data, int num_pixels, int i)
{
  IACA_START for (i = 0; i < num_pixels; ++i)
    {
      const int argb = argb_data[i];
      const int green = (argb >> 8) & 0xff;
      const uint32_t new_r = (((argb >> 16) & 0xff) - green) & 0xff;
      const uint32_t new_b = (((argb >> 0) & 0xff) - green) & 0xff;
      argb_data[i] = (argb & 0xff00ff00u) | (new_r << 16) | new_b;
}IACA_END}
