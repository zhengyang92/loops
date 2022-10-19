#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int *histo, int x, const uint32_t * argb, int tile_width, int red_to_blue,
    int green_to_blue)
{
  for (x = 0; x < tile_width; ++x)
    {
      ++histo[TransformColorBlue (green_to_blue, red_to_blue, argb[x])];
    }
}
