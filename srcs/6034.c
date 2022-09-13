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
fn (const int32_t combinatorial_table[6][30], int temp,
    const int16_t fixed_cb_gain[24], int i, G723_1_Subframe * subfrm,
    int16_t * vector, int j)
{
  for (i = 0; i < 60 / 2; i++)
    {
      temp -= combinatorial_table[j][i];
      if (temp >= 0)
	continue;
      temp += combinatorial_table[j++][i];
      if (subfrm->pulse_sign & (1 << (6 - j)))
	{
	  vector[subfrm->grid_index + 2 * i] =
	    -fixed_cb_gain[subfrm->amp_index];
	}
      else
	{
	  vector[subfrm->grid_index + 2 * i] =
	    fixed_cb_gain[subfrm->amp_index];
	}
      if (j == 6)
	break;
    }
}
