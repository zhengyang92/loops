#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int ff_mdct_win_fixed[8][40], float ff_mdct_win_float[8][40], int i,
    int j)
{
  IACA_START for (j = 0; j < 4; j++)
    {
      double d;
      if (j == 2 && i % 3 != 1)
	continue;
      d = sin (3.14159265358979323846 * (i + 0.5) / 36.0);
      if (j == 1)
	{
	  if (i >= 30)
	    d = 0;
	  else if (i >= 24)
	    d = sin (3.14159265358979323846 * (i - 18 + 0.5) / 12.0);
	  else if (i >= 18)
	    d = 1;
	}
      else if (j == 3)
	{
	  if (i < 6)
	    d = 0;
	  else if (i < 12)
	    d = sin (3.14159265358979323846 * (i - 6 + 0.5) / 12.0);
	  else if (i < 18)
	    d = 1;
	}
      d *= 0.5 * 1.759 / cos (3.14159265358979323846 * (2 * i + 19) / 72);
      if (j == 2)
	{
	  ff_mdct_win_float[j][i / 3] = d / (1 << 5);
	  ff_mdct_win_fixed[j][i / 3] = d / (1 << 5) * (1LL << 32) + 0.5;
	}
      else
	{
	  int idx =
	    i <
	    18 ? i : i + ((((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2 - 18);
	  ff_mdct_win_float[j][idx] = d / (1 << 5);
	  ff_mdct_win_fixed[j][idx] = d / (1 << 5) * (1LL << 32) + 0.5;
}IACA_END}}
