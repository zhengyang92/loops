#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int subbnd, GetBitContext * gbc, int n_subbands, uint8_t * band_struct)
{
  for (subbnd = 0; subbnd < n_subbands - 1; subbnd++)
    {
      band_struct[subbnd] = get_bits1 (gbc);
    }
}
