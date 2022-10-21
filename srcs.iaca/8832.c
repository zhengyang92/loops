#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int16_t int16_t;

int
fn (int y, int x, int src_offset, const int16_t * in, int bits_per_raw_sample,
    int dst_offset, uint16_t * dst)
{
  for (x = 0; x < 8; x++)
     { IACA_START
      src_offset = (y << 3) + x;
      if (bits_per_raw_sample == 10)
	{
	  dst[dst_offset + x] =
	    (av_clip_c
	     ((in[src_offset]), (1 << 2), (1 << 10) - (1 << 2) - 1));
	}
      else
	{
	  dst[dst_offset + x] =
	    (av_clip_c
	     ((in[src_offset]), (1 << 2), (1 << 12) - (1 << 2) - 1));
	}
     } IACA_END
}
