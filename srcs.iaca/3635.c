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
      int32_t sam, tmp;
      sam = dpp->samplesA[0];
      dpp->samplesA[0] = dpp->samplesA[1];
      out_left[i] = tmp = (dpp->samplesA[1] =
			   in_left[i]) - (((dpp->weightA) * (sam) +
					   512) >> 10);
      if ((sam) && (tmp))
	{
	  int32_t s = (int32_t) ((sam) ^ (tmp)) >> 31;
	  dpp->weightA = ((dpp->delta) ^ s) + ((dpp->weightA) - s);
	};
      sam = dpp->samplesB[0];
      dpp->samplesB[0] = dpp->samplesB[1];
      out_right[i] = tmp = (dpp->samplesB[1] =
			    in_right[i]) - (((dpp->weightB) * (sam) +
					     512) >> 10);
      if ((sam) && (tmp))
	{
	  int32_t s = (int32_t) ((sam) ^ (tmp)) >> 31;
	  dpp->weightB = ((dpp->delta) ^ s) + ((dpp->weightB) - s);
	};
    }
}
