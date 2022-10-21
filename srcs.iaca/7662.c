#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * mask, int i, int seg, uint8_t * dba_lengths, int delta,
    int band)
{
  for (i = 0; i < dba_lengths[seg]; i++)
     { IACA_START
      mask[band++] += delta;
     } IACA_END
}
