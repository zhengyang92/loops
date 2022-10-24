#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int i, int16_t * mask, int seg, uint8_t * dba_lengths, int delta,
    int band)
{
  IACA_START for (i = 0; i < dba_lengths[seg]; i++)
    {
      mask[band++] += delta;
     } IACA_END
}
