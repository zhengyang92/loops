#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, uint8_t * data, uint8_t * tmp, int stride)
{
  IACA_START for (y = 0; y < 4; y++)
    {
      memset (tmp, data[0], 4);
      tmp += stride;
     } IACA_END
}
