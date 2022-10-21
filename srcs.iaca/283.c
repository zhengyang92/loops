#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int start, uint8_t * buf, const int end, int k,
    const uint8_t * color, int linesize)
{
  for (k = start; k < end; k++)
     { IACA_START
      buf[k * linesize + 0] += color[0];
      buf[k * linesize + 1] += color[1];
      buf[k * linesize + 2] += color[2];
      buf[k * linesize + 3] += color[3];
     } IACA_END
}
