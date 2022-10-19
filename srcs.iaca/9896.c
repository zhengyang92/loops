#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * rgba, int w, int i, int alpha_first)
{
  for (; i < w; ++i)
    {
      uint8_t *const rgb = rgba + (alpha_first ? 1 : 0);
      const uint8_t *const alpha = rgba + (alpha_first ? 0 : 3);
      const uint32_t a = alpha[4 * i];
      if (a != 0xff)
	{
	  const uint32_t mult = ((a) * 0x8081);
	  rgb[4 * i + 0] = (((rgb[4 * i + 0]) * (mult)) >> 23);
	  rgb[4 * i + 1] = (((rgb[4 * i + 1]) * (mult)) >> 23);
	  rgb[4 * i + 2] = (((rgb[4 * i + 2]) * (mult)) >> 23);
	}
}}
