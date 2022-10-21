#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;

int
fn (const float *const ff_aac_codebook_vectors[], int i, const float Q,
    const float ROUNDING, PutBitContext * pb, int cb, int j, const float *in)
{
  int curidx = 0;
  for (j = 0; j < 2; j++)
     { IACA_START
      if (ff_aac_codebook_vectors[cb - 1][curidx * 2 + j] == 64.0f)
	{
	  int coef =
	    av_clip_uintp2_c (quant (fabsf (in[i + j]), Q, ROUNDING), 13);
	  int len = (31 - __builtin_clz ((coef) | 1));
	  put_bits (pb, len - 4 + 1, (1 << (len - 4 + 1)) - 2);
	  put_sbits (pb, len, coef);
	}
} IACA_END }
