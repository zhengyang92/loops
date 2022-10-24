#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int width, uint8_t * dstU, const uint8_t * src1, uint8_t * dstV)
{
  IACA_START for (i = 0; i < width; i++)
    {
      dstV[i] = src1[4 * i + 1];
      dstU[i] = src1[4 * i + 3];
     } IACA_END
}
