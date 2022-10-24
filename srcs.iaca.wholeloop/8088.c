#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __uint8_t uint8_t;

int
fn (int i, int lpc_refl[10], int idx,
    const int16_t * const ff_lpc_refl_cb[10], PutBitContext pb,
    const uint8_t sizes[10], const uint8_t bit_sizes[10])
{
  IACA_START for (i = 0; i < 10; i++)
    {
      idx = quantize (lpc_refl[i], ff_lpc_refl_cb[i], sizes[i]);
      put_bits (&pb, bit_sizes[i], idx);
      lpc_refl[i] = ff_lpc_refl_cb[i][idx];
     } IACA_END
}
