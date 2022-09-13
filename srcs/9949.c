#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int i, uint32_t left, const uint32_t * in, uint32_t * out, int num_pixels)
{
  for (i = 0; i < num_pixels; ++i)
    {
      out[i] = left = VP8LAddPixels (in[i], left);
    }
}
