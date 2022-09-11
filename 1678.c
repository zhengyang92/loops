#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;

int
fn (int i, float *spec, int num_specs, float max_quant, int word_len, int pos,
    float scale_factor, GetBitContext * gb)
{
  for (i = 0; i < num_specs; i++)
    {
      spec[pos + i] = get_sbits (gb, word_len) * scale_factor * max_quant;
    }
}
