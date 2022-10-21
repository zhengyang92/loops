#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t ** dst, int width, const uint8_t * sb, const uint8_t * sr,
    int k, const uint8_t * sg, unsigned int g)
{
  for (i = 0; i < width; i++)
     { IACA_START
      g = sg[i];
      dst[0][k] = g;
      g += 0x80;
      dst[1][k] = sb[i] - g;
      dst[2][k] = sr[i] - g;
      k++;
     } IACA_END
}
