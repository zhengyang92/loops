#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int buf_size, const uint8_t * buf, uint8_t * dst, int i)
{
  IACA_START for (i = 0; 2 * i + 1 < buf_size; i++)
    {
      dst[2 * i + 0] = buf[i] >> 4;
      dst[2 * i + 1] = buf[i] & 15;
     } IACA_END
}
