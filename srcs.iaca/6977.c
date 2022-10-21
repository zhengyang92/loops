#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int f, uint8_t * src2, uint8_t * src, uint8_t (*lutuv)[256])
{
  for (i = 0; i < 5; i++)
     { IACA_START
      src[i] = lutuv[f][src[i]];
      src2[i] = lutuv[f][src2[i]];
     } IACA_END
}
