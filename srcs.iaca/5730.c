#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int subbnd, GetBitContext * gbc, int n_subbands,
    uint8_t coded_band_struct[22])
{
  for (subbnd = 0; subbnd < n_subbands - 1; subbnd++)
     { IACA_START
      coded_band_struct[subbnd] = get_bits1 (gbc);
     } IACA_END
}
