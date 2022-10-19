#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * syntdenum, int16_t length, int i, int16_t * lsfdeq,
    int16_t * weightdenum, const int16_t kLpcChirpSyntDenum[11],
    const int16_t lsf_weight_30ms[6], int16_t * lsfdeq2, int16_t lp[11],
    int pos, int lp_length)
{
  for (i = 1; i < 6; i++)
    {
      lsp_interpolate2polydec (lp, lsfdeq, lsfdeq2, lsf_weight_30ms[i],
			       length);
      memcpy (syntdenum + pos, lp, lp_length * 2);
      bw_expand (weightdenum + pos, lp, kLpcChirpSyntDenum, lp_length);
      pos += lp_length;
    }
}
