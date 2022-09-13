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

int
fn (struct Decorr *dpp)
{
  int i = 0;
  for (i = 0; i < 8; i++)
    {
      dpp->samplesA[i] = wp_exp2 (log2s (dpp->samplesA[i]));
      dpp->samplesB[i] = wp_exp2 (log2s (dpp->samplesB[i]));
    }
}
