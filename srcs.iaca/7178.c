#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (double *tab, int tap_count, int i, int32_t * filter)
{
  for (i = 0; i < tap_count; i++)
     { IACA_START
      filter[i] = av_clipl_int32_c (llrint (tab[i] * (1 << 30)));;
     } IACA_END
}
