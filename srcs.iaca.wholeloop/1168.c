#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * xf0, const uint8_t * xf1, const int size)
{
  float sum1 = 0.f;
  float sum0 = 0.f;
  IACA_START for (int x = 0; x < size; x++)
    {
      sum0 += xf0[x];
      sum1 += xf1[x];
}IACA_END}
