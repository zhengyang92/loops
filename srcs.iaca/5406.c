#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __int32_t int32_t;

int
fn (int32_t * samples_l, int i, const int sent_bits, int32_t * samples_r,
    int nb_samples, PutBitContext * pb, int pre_shift)
{
  for (i = 0; i < nb_samples; i++)
     { IACA_START
      put_sbits (pb, sent_bits, samples_l[i] >> pre_shift);
      put_sbits (pb, sent_bits, samples_r[i] >> pre_shift);
     } IACA_END
}
