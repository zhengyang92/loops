#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;

int
fn (float *spec, int i, int num_specs, float max_quant, int word_len, int pos,
    float scale_factor, GetBitContext * gb)
{
  IACA_START for (i = 0; i < num_specs; i++)
    {
      spec[pos + i] = get_sbits (gb, word_len) * scale_factor * max_quant;
     } IACA_END
}
