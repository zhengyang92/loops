#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t d, uint32_t c, uint32_t a, uint32_t * lut)
{
  IACA_START for (int j = 0; j < 1 << d; j++)
    {
      uint32_t f = 0xFFFFFFFFu;
      c &= 0xFFFFFFu;
      if ((c & 0xFF00u) != 0x8000u)
	fill_elements (j, d, &c, &f);
      lut[2 * a + 2 * j] = c;
      lut[2 * a + 2 * j + 1] = f;
     } IACA_END
}
