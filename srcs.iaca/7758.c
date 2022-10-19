#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t ff_dv_quant_shifts[22][4], int i, uint32_t * factor2,
    const uint8_t dv_quant_areas[4], int c, const uint16_t * iweight1, int s,
    uint32_t * factor1)
{
  for (; i < dv_quant_areas[c]; i++)
    {
      *factor1 = iweight1[i] << (ff_dv_quant_shifts[s][c] + 1);
      *factor2++ = (*factor1++) << 1;
    }
}
