#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * src, uint8_t * dst, int i, int stride)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      dst[0] += (unsigned) src[0];
      dst[1] += (unsigned) src[1];
      dst[2] += (unsigned) src[2];
      dst[3] += (unsigned) src[3];
      dst += stride;
      src += 4;
}IACA_END}
