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
      sam_B = dpp->samplesB[0];
      samples_r[i] = tmp = (sam_A =
			    samples_r[i]) - ((sam_B) !=
					     (short) (sam_B)
					     ? ((((((sam_B) & 0xffff) *
						   (dpp->weightB)) >> 9) +
						 ((((sam_B) & ~0xffff) >> 9) *
						  (dpp->weightB)) +
						 1) >> 1) : (((dpp->weightB) *
							      (sam_B) +
							      512) >> 10));
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
      samples_l[i] = tmp = (dpp->samplesB[0] =
			    samples_l[i]) - ((sam_A) !=
					     (short) (sam_A)
					     ? ((((((sam_A) & 0xffff) *
						   (dpp->weightA)) >> 9) +
						 ((((sam_A) & ~0xffff) >> 9) *
						  (dpp->weightA)) +
						 1) >> 1) : (((dpp->weightA) *
							      (sam_A) +
							      512) >> 10));
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
