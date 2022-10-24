#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int width, uint8_t * luma_ptr, const uint8_t * alpha_ptr,
    const uint8_t avg_u8)
{
  IACA_START for (x = 0; x < width; ++x)
    {
      if (alpha_ptr[x] == 0)
	luma_ptr[x] = avg_u8;
     } IACA_END
}
