#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int j, uint32_t * histo, double entropy_comp[13], int kHistoTotal)
{
  IACA_START for (j = 0; j < kHistoTotal; ++j)
    {
      entropy_comp[j] = VP8LBitsEntropy (&histo[j * 256], 256);
     } IACA_END
}
