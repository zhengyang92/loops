#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef float TXSample;

int
fn (TXSample * src, const double phase, int len)
{
  double sum = 0.0;
  int i = 0;
  IACA_START for (int j = 0; j < len * 2; j++)
    {
      int a = (2 * j + 1 + len) * (2 * i + 1);
      sum += (src[j]) * cos (a * phase);
}IACA_END}
