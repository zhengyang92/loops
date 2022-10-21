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
fn (int32_t * samples_l, int i, int32_t * samples_r, int nb_samples, int m,
    int k, struct Decorr *dpp)
{
  for (m = 0, k = dpp->value & (8 - 1), i = 0; i < nb_samples; i++)
     { IACA_START
      int32_t sam, tmp;
      sam = dpp->samplesA[m];
      samples_l[i] = tmp = (dpp->samplesA[k] =
			    samples_l[i]) - ((sam) !=
					     (short) (sam)
					     ? ((((((sam) & 0xffff) *
						   (dpp->weightA)) >> 9) +
						 ((((sam) & ~0xffff) >> 9) *
						  (dpp->weightA)) +
						 1) >> 1) : (((dpp->weightA) *
							      (sam) +
							      512) >> 10));
      if ((sam) && (tmp))
	{
	  int32_t s = (int32_t) ((sam) ^ (tmp)) >> 31;
	  dpp->weightA = ((dpp->delta) ^ s) + ((dpp->weightA) - s);
	};
      sam = dpp->samplesB[m];
      samples_r[i] = tmp = (dpp->samplesB[k] =
			    samples_r[i]) - ((sam) !=
					     (short) (sam)
					     ? ((((((sam) & 0xffff) *
						   (dpp->weightB)) >> 9) +
						 ((((sam) & ~0xffff) >> 9) *
						  (dpp->weightB)) +
						 1) >> 1) : (((dpp->weightB) *
							      (sam) +
							      512) >> 10));
      if ((sam) && (tmp))
	{
	  int32_t s = (int32_t) ((sam) ^ (tmp)) >> 31;
	  dpp->weightB = ((dpp->delta) ^ s) + ((dpp->weightB) - s);
	};
      m = (m + 1) & (8 - 1);
      k = (k + 1) & (8 - 1);
     } IACA_END
}
