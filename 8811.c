#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int idx_max, uint8_t (*path)[35768], int i, float tmp,
    float (*opt)[35768], int idx, float power_candidate, int idx_min,
    int band, int j, const int16_t ff_nelly_delta_table[32])
{
  int c = 0;
  for (j = 0; j < 32; j++)
    {
      idx = i + ff_nelly_delta_table[j];
      if (idx > idx_max)
	break;
      if (idx >= idx_min)
	{
	  tmp = opt[band - 1][i] + distance (idx, power_candidate, band);
	  if (opt[band][idx] > tmp)
	    {
	      opt[band][idx] = tmp;
	      path[band][idx] = j;
	      c = 1;
	    }
	}
    }
}
