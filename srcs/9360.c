#include <stdint.h>
#include <stdio.h>






int
fn (float snr_limit, int i, int *bandWidthT, float workT2[32],
    float *flcoeffs2, float *flcoeffs3, float *flcoeffs5, float workT3[32],
    float *flcoeffs1, float workT1[32])
{
  for (i = 0; i < 32; i++)
    {
      flcoeffs5[i] = workT2[i] = 0.0;
      if (bandWidthT[i])
	{
	  workT1[i] = flcoeffs1[i] * flcoeffs1[i];
	  flcoeffs3[i] = 2.0 * flcoeffs2[i];
	}
      else
	{
	  workT1[i] = 0.0;
	  flcoeffs3[i] = -30000.0;
	}
      workT3[i] = bandWidthT[i] * workT1[i] * 0.01;
      if (workT3[i] <= snr_limit)
	workT3[i] = 0.0;
    }
}
