#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (double *tab, int tap_count, int i, int16_t * filter)
{
  IACA_START for (i = 0; i < tap_count; i++)
    {
      filter[i] = av_clip_int16_c (lrint (tab[i] * (1 << 15)));
     } IACA_END
}
