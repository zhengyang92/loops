#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t (*mant_cnt)[16], int blk)
{
  IACA_START for (blk = 0; blk < 6; blk++)
    {
      memset (mant_cnt[blk], 0, sizeof (mant_cnt[blk]));
      mant_cnt[blk][1] = mant_cnt[blk][2] = 2;
      mant_cnt[blk][4] = 1;
     } IACA_END
}
