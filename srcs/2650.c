#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int dim, int16_t * lsf)
{
  int m = 0;
  for (int k = 0; k < dim - 1; k++)
    {
      int i = m * dim + k;
      if ((lsf[i + 1] - lsf[i]) < 319)
	{
	  if (lsf[i + 1] < lsf[i])
	    {
	      lsf[i + 1] = lsf[i] + 160;
	      lsf[i] = lsf[i + 1] - 160;
	    }
	  else
	    {
	      lsf[i] -= 160;
	      lsf[i + 1] += 160;
	    }
	}
      lsf[i] = av_clip_c (lsf[i], 82, 25723);
    }
}
