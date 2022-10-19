#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float ff_aac_pow2sf_tab[428], float ff_aac_pow34sf_tab[428],
    int t1_inc_cur, float t2, const float exp2_lut[16], float t1,
    int t2_inc_cur)
{
  int t2_inc_prev = 8;
  int t1_inc_prev = 0;
  for (int i = 0; i < 428; i++)
    {
      t1_inc_cur = 4 * (i % 4);
      t2_inc_cur = (8 + 3 * i) % 16;
      if (t1_inc_cur < t1_inc_prev)
	t1 *= 2;
      if (t2_inc_cur < t2_inc_prev)
	t2 *= 2;
      ff_aac_pow2sf_tab[i] = t1 * exp2_lut[t1_inc_cur];
      ff_aac_pow34sf_tab[i] = t2 * exp2_lut[t2_inc_cur];
      t1_inc_prev = t1_inc_cur;
      t2_inc_prev = t2_inc_cur;
    }
}
