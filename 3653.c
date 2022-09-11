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
fn (int32_t * samples_l, int i, int32_t * samples_r, int nb_samples,
    struct Decorr *dpp)
{
  for (i = 0; i < nb_samples; i++)
    {
      int32_t sam_A, sam_B, tmp;
      sam_A = dpp->samplesA[0];
      samples_l[i] = tmp = (sam_B =
			    samples_l[i]) - (((dpp->weightA) * (sam_A) +
					      512) >> 10);
      if (sam_A && tmp)
	{
	  const int32_t s = (sam_A ^ tmp) >> 31;
	  if ((dpp->weightA = (dpp->weightA ^ s) + (2 - s)) > 1024)
	    dpp->weightA = 1024;
	  dpp->weightA = (dpp->weightA ^ s) - s;
	};
      samples_r[i] = tmp = (dpp->samplesA[0] =
			    samples_r[i]) - (((dpp->weightB) * (sam_B) +
					      512) >> 10);
      if (sam_B && tmp)
	{
	  const int32_t s = (sam_B ^ tmp) >> 31;
	  if ((dpp->weightB = (dpp->weightB ^ s) + (2 - s)) > 1024)
	    dpp->weightB = 1024;
	  dpp->weightB = (dpp->weightB ^ s) - s;
	};
    }
}
