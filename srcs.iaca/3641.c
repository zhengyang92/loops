#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct Decorr
{
  int delta;
  int value;
  int weightA;
  int weightB;
  int samplesA[8];
  int samplesB[8];
  int sumA;
  int sumB;
} Decorr;
typedef __int32_t int32_t;

int
fn (int32_t * in_right, int32_t * out_left, int nb_samples,
    int32_t * out_right, int32_t * in_left, struct Decorr *dpp)
{
  int i = 0;
  for (i = 0; i < nb_samples; i++)
    {
      int32_t sam_A, sam_B, tmp;
      sam_A = dpp->samplesA[0];
      sam_B = dpp->samplesB[0];
      dpp->samplesA[0] = tmp = in_right[i];
      out_right[i] = tmp -= (((dpp->weightB) * (sam_B) + 512) >> 10);
      if ((sam_B) && (tmp))
	{
	  if (((sam_B) ^ (tmp)) < 0)
	    {
	      (dpp->weightB) -= (dpp->delta);
	      if ((dpp->weightB) < -1024)
		(dpp->weightB) = -1024;
	    }
	  else
	    {
	      (dpp->weightB) += (dpp->delta);
	      if ((dpp->weightB) > 1024)
		(dpp->weightB) = 1024;
	    }
	};
      dpp->samplesB[0] = tmp = in_left[i];
      out_left[i] = tmp -= (((dpp->weightA) * (sam_A) + 512) >> 10);
      if ((sam_A) && (tmp))
	{
	  if (((sam_A) ^ (tmp)) < 0)
	    {
	      (dpp->weightA) -= (dpp->delta);
	      if ((dpp->weightA) < -1024)
		(dpp->weightA) = -1024;
	    }
	  else
	    {
	      (dpp->weightA) += (dpp->delta);
	      if ((dpp->weightA) > 1024)
		(dpp->weightA) = 1024;
	    }
	};
    }
}
