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
fn (int32_t * samples_l, int i, int32_t * samples_r, int nb_samples,
    struct Decorr *dpp)
{
  for (i = 0; i < nb_samples; i++)
     { IACA_START
      int32_t sam, tmp;
      sam = dpp->samplesA[0] + ((dpp->samplesA[0] - dpp->samplesA[1]) >> 1);
      dpp->samplesA[1] = dpp->samplesA[0];
      samples_l[i] = tmp = (dpp->samplesA[0] =
			    samples_l[i]) - (((dpp->weightA) * (sam) +
					      512) >> 10);
      if (sam && tmp)
	dpp->weightA -= (((sam ^ tmp) >> 29) & 4) - 2;;
      sam = dpp->samplesB[0] + ((dpp->samplesB[0] - dpp->samplesB[1]) >> 1);
      dpp->samplesB[1] = dpp->samplesB[0];
      samples_r[i] = tmp = (dpp->samplesB[0] =
			    samples_r[i]) - (((dpp->weightB) * (sam) +
					      512) >> 10);
      if (sam && tmp)
	dpp->weightB -= (((sam ^ tmp) >> 29) & 4) - 2;;
     } IACA_END
}
