#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * weight, int i)
{
  int sum = 1;
  IACA_START for (i = 0; i < 64; i++)
    {
      int one = 36;
      int qns = 4;
      int w;
      w = ((weight[i]) >= 0 ? (weight[i]) : (-(weight[i]))) + qns * one;
      w = 15 + (48 * qns * one + w / 2) / w;
      weight[i] = w;
      ((void) (0));
      ((void) (0));
      sum += w * w;
}IACA_END}
