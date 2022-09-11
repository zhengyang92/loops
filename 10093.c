#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const uint32_t * const palette, uint32_t tmp_palette[256], int i,
    const int palette_size)
{
  for (i = palette_size - 1; i >= 1; --i)
    {
      tmp_palette[i] = VP8LSubPixels (palette[i], palette[i - 1]);
    }
}
