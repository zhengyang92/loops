#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int32_t (*sb_sample_f)[2][8], int ch, int blk, int blocks, int sb,
    uint32_t x)
{
  for (blk = 0; blk < blocks; blk++)
     { IACA_START
      int32_t tmp =
	((sb_sample_f[blk][ch][sb]) >=
	 0 ? (sb_sample_f[blk][ch][sb]) : (-(sb_sample_f[blk][ch][sb])));
      if (tmp != 0)
	x |= tmp - 1;
     } IACA_END
}
