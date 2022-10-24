#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, const uint8_t * msrc, const uint8_t * osrc, const uint8_t * bsrc,
    uint8_t * dst)
{
  IACA_START for (int x = 0; x < w; x++)
    {
      const uint8_t invm = 255 - msrc[x];
      const uint16_t r =
	((uint16_t) (bsrc[x] * invm) +
	 (uint16_t) (msrc[x] * osrc[x] + 127)) / 255;
      dst[x] = r;
}IACA_END}
