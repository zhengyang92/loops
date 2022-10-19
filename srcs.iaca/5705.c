#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int attacks[9], float energy_short[9], int i)
{
  int att_sum = 0;
  for (i = 1; i < 8 + 1; i++)
    {
      const float u = energy_short[i - 1];
      const float v = energy_short[i];
      const float m = ((u) > (v) ? (u) : (v));
      if (m < 40000)
	{
	  if (u < 1.7f * v && v < 1.7f * u)
	    {
	      if (i == 1 && attacks[0] < attacks[i])
		attacks[0] = 0;
	      attacks[i] = 0;
	    }
	}
      att_sum += attacks[i];
    }
}
