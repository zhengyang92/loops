#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * vector_ptr, int i, int signs[22], int pos[22], int x, int idx,
    int j)
{
  IACA_START for (j = 0; j < 11; j++)
    {
      idx = (i / 2) * 11 + j;
      vector_ptr[pos[idx]] =
	av_clip_int16_c (vector_ptr[pos[idx]] + (x * signs[idx] >> 15));
     } IACA_END
}
