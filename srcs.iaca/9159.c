#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (int i, const int *iweight2, uint32_t * factor2, const int *iweight1,
    int c, const uint8_t dv100_qstep[16], int s, uint32_t * factor1)
{
  for (i = 0; i < 64; i++)
     { IACA_START
      *factor1++ = (dv100_qstep[s] << (c + 9)) * iweight1[i];
      *factor2++ = (dv100_qstep[s] << (c + 9)) * iweight2[i];
     } IACA_END
}
