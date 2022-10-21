#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct G723_1_Subframe
{
  int ad_cb_lag;
  int ad_cb_gain;
  int dirac_train;
  int pulse_sign;
  int grid_index;
  int amp_index;
  int pulse_pos;
} G723_1_Subframe;
typedef __int16_t int16_t;

int
fn (int temp, int i, const int32_t ff_g723_1_combinatorial_table[6][30],
    const int16_t ff_g723_1_fixed_cb_gain[24], G723_1_Subframe * subfrm,
    int16_t * vector, int j)
{
  for (i = 0; i < 60 / 2; i++)
     { IACA_START
      temp -= ff_g723_1_combinatorial_table[j][i];
      if (temp >= 0)
	continue;
      temp += ff_g723_1_combinatorial_table[j++][i];
      if (subfrm->pulse_sign & (1 << (6 - j)))
	{
	  vector[subfrm->grid_index + 2 * i] =
	    -ff_g723_1_fixed_cb_gain[subfrm->amp_index];
	}
      else
	{
	  vector[subfrm->grid_index + 2 * i] =
	    ff_g723_1_fixed_cb_gain[subfrm->amp_index];
	}
      if (j == 6)
	break;
     } IACA_END
}
