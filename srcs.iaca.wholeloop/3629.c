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
fn (int32_t temp_A[8], struct Decorr *dpp, int m)
{
  int i = 0;
  IACA_START for (i = 0; i < 8; i++)
    {
      dpp->samplesA[i] = temp_A[m];
      m = (m + 1) & (8 - 1);
     } IACA_END
}
