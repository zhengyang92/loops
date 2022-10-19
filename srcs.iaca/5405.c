#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __int32_t int32_t;

int
fn (int32_t * samples_l, int i, const int sent_bits, int nb_samples,
    PutBitContext * pb, int pre_shift)
{
  for (i = 0; i < nb_samples; i++)
    {
      put_sbits (pb, sent_bits, samples_l[i] >> pre_shift);
    }
}
