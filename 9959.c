#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int *histo, int x, int green_to_red, const uint32_t * argb,
    int tile_width)
{
  for (x = 0; x < tile_width; ++x)
    {
      ++histo[TransformColorRed (green_to_red, argb[x])];
    }
}
