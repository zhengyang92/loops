#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t palette[16], int count, int i)
{
  IACA_START for (i = 0; i < count; i++)
    {
      palette[i] = rgb_to_yuv (palette[i]);
     } IACA_END
}
