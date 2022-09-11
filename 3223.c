#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint32_t uint32_t;

int
fn (int32_t tmp1, uint32_t y, int32_t sb_sample_j[16][2],
    int32_t (*sb_sample_f)[2][8], int32_t tmp0, int blk, int blocks, int sb,
    uint32_t x)
{
  for (blk = 0; blk < blocks; blk++)
    {
      tmp0 = sb_sample_f[blk][0][sb];
      tmp1 = sb_sample_f[blk][1][sb];
      sb_sample_j[blk][0] = (tmp0 >> 1) + (tmp1 >> 1);
      sb_sample_j[blk][1] = (tmp0 >> 1) - (tmp1 >> 1);
      tmp0 = ((tmp0) >= 0 ? (tmp0) : (-(tmp0)));
      tmp1 = ((tmp1) >= 0 ? (tmp1) : (-(tmp1)));
      if (tmp0 != 0)
	x |= tmp0 - 1;
      if (tmp1 != 0)
	y |= tmp1 - 1;
    }
}
