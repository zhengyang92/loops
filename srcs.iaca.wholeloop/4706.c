#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (uint8_t * obmc_weight, int xblen, int x, int dc, uint16_t * dst)
{
  IACA_START for (x = 0; x < xblen; x += 2)
    {
      dst[x] += dc * obmc_weight[x];
      dst[x + 1] += dc * obmc_weight[x + 1];
     } IACA_END
}
