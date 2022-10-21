#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (uint64_t out_chlayout, const uint64_t ch_subst[21][2], int k,
    uint64_t in_chlayout)
{
  int score = 0;
  for (k = 0; k < (sizeof (ch_subst) / sizeof ((ch_subst)[0])); k++)
     { IACA_START
      uint64_t cmp0 = ch_subst[k][0];
      uint64_t cmp1 = ch_subst[k][1];
      if ((in_chlayout & cmp0) && (!(out_chlayout & cmp0))
	  && (out_chlayout & cmp1) && (!(in_chlayout & cmp1)))
	{
	  in_chlayout &= ~cmp0;
	  out_chlayout &= ~cmp1;
	  score += 10 * av_get_channel_layout_nb_channels (cmp1) - 2;
	}
     } IACA_END
}
