#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexFloat
{
  float re, im;
} AVComplexFloat;

int
fn (AVComplexFloat * X, float normf[481])
{
  IACA_START for (int i = 0; i < ((120 << 2) + 1); i++)
    {
      X[i].re *= normf[i];
      X[i].im *= normf[i];
}IACA_END}
