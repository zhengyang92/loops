#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (const uint64_t ch_subst[21][2], uint64_t out_chlayout, int k,
    uint64_t in_chlayout)
{
  int score = 0;
  for (k = 0; k < (sizeof (ch_subst) / sizeof ((ch_subst)[0])); k++)
    {
      uint64_t cmp0 = ch_subst[k][0];
      uint64_t cmp1 = ch_subst[k][1];
      if ((in_chlayout & cmp0) && (!(out_chlayout & cmp0))
	  && (out_chlayout & cmp1) && (!(in_chlayout & cmp1)))
	{
	  in_chlayout &= ~cmp0;
	  out_chlayout &= ~cmp1;
	  score += 10 * av_get_channel_layout_nb_channels (cmp1) - 2;
	}
    }
}
