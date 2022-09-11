#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, uint8_t * const rgb, const uint8_t * const alpha, int i)
{
  for (i = 0; i < w; ++i)
    {
      const uint32_t a = alpha[4 * i];
      if (a != 0xff)
	{
	  const uint32_t mult = ((a) * 32897U);
	  rgb[4 * i + 0] = (((rgb[4 * i + 0]) * (mult)) >> 23);
	  rgb[4 * i + 1] = (((rgb[4 * i + 1]) * (mult)) >> 23);
	  rgb[4 * i + 2] = (((rgb[4 * i + 2]) * (mult)) >> 23);
	}
}}
