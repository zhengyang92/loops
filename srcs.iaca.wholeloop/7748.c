#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, uint8_t * block, int weight, int log2_denom)
{
  IACA_START for (x = 0; x < 8; x++)
    {
      block[x] =
	av_clip_uint8_c ((block[x] * weight +
			  (1 << (log2_denom - 1))) >> log2_denom);
      block[x + 1] =
	av_clip_uint8_c ((block[x + 1] * weight +
			  (1 << (log2_denom - 1))) >> log2_denom);
     } IACA_END
}
