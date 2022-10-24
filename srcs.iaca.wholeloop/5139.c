#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float *pptr, float pval, int i,
    const uint8_t ff_nelly_band_sizes_table[23], float val, float *bptr,
    int j)
{
  IACA_START for (j = 0; j < ff_nelly_band_sizes_table[i]; j++)
    {
      *bptr++ = val;
      *pptr++ = pval;
     } IACA_END
}
