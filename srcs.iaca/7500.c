#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, int y, const int linesize, int x, const int start_left,
    const uint8_t fill)
{
  for (x = 0; x < start_left; x++)
    {
      int src = ptr[y * linesize + x];
      ptr[y * linesize + x] = lerp8 (fill, src, start_left - x, start_left);
}}
