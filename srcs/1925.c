#include <stdint.h>
#include <stdio.h>






int
fn (int max_v, int i, const int16_t lwc_gain_tab[11][7], int k, int j,
    int *msk_val)
{
  int thr = 0;
  int max_j = 0;
  for (j = ((i - 3) > (0) ? (i - 3) : (0)), k = 0; j <= i + 3; j++, k++)
    {
      int v = msk_val[j] + lwc_gain_tab[i][k];
      if (v > max_v)
	{
	  max_j = j;
	  max_v = v;
	}
      thr = log_add (thr, v);
    }
}
