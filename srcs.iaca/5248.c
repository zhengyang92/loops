#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __int32_t int32_t;

int
fn (uint32_t y, int32_t tmp1, int32_t sb_sample_j[16][2], int32_t tmp0,
    int blk, int blocks, uint32_t x)
{
  for (blk = 0; blk < blocks; blk++)
     { IACA_START
      tmp0 =
	((sb_sample_j[blk][0]) >=
	 0 ? (sb_sample_j[blk][0]) : (-(sb_sample_j[blk][0])));
      tmp1 =
	((sb_sample_j[blk][1]) >=
	 0 ? (sb_sample_j[blk][1]) : (-(sb_sample_j[blk][1])));
      if (tmp0 != 0)
	x |= tmp0 - 1;
      if (tmp1 != 0)
	y |= tmp1 - 1;
     } IACA_END
}
