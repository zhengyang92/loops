#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;

int
fn (int i, const float Q, PutBitContext * pb, int cb,
    const float *ff_aac_codebook_vectors[], int j, const float *in)
{
  int curidx = 0;
  for (j = 0; j < 2; j++)
     { IACA_START
      if (ff_aac_codebook_vectors[cb - 1][curidx * 2 + j] == 64.0f)
	{
	  int coef = av_clip_uintp2_c (quant (fabsf (in[i + j]), Q), 13);
	  int len = (31 - __builtin_clz ((coef) | 1));
	  put_bits (pb, len - 4 + 1, (1 << (len - 4 + 1)) - 2);
	  put_bits (pb, len, coef & ((1 << len) - 1));
	}
} IACA_END }
