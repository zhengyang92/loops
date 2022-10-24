#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int v, unsigned char *dst, int n, uint8_t linear_to_alaw[16384],
    const short *samples)
{
  IACA_START for (; n > 0; n--)
    {
      v = *samples++;
      *dst++ = linear_to_alaw[(v + 32768) >> 2];
     } IACA_END
}
