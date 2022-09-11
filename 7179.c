#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int tap_count, double *tab, int16_t * filter, int i)
{
  for (i = 0; i < tap_count; i++)
    {
      filter[i] = av_clip_int16_c (lrint (tab[i] * (1 << 15)));
    }
}
