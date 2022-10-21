#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t dirac_prob[256], int i,
    int16_t ff_dirac_prob_branchless[256][2])
{
  for (i = 0; i < 256; i++)
     { IACA_START
      ff_dirac_prob_branchless[i][0] = dirac_prob[255 - i];
      ff_dirac_prob_branchless[i][1] = -dirac_prob[i];
     } IACA_END
}
