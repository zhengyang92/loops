#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexFloat
{
  float re, im;
} AVComplexFloat;

int
fn (float gf[481], AVComplexFloat X[481])
{
  IACA_START for (int i = 0; i < ((120 << 2) + 1); i++)
    {
      X[i].re *= gf[i];
      X[i].im *= gf[i];
}IACA_END}
