#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int y, int x, int src_offset, const int16_t * in, int dst_offset,
    uint16_t * dst)
{
  for (x = 0; x < 8; x++)
     { IACA_START
      src_offset = (y << 3) + x;
      dst[dst_offset + x] =
	(av_clip_c
	 ((in[src_offset]) + (1 << (10 - 1)), (1 << (10 - 8)),
	  (1 << 10) - (1 << (10 - 8)) - 1));
     } IACA_END
}
