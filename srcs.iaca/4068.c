#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int32_t TXSample;

int
fn (TXSample * src, const double phase, int len)
{
  double sum = 0.0;
  int i = 0;
  for (int j = 0; j < len * 2; j++)
    {
      int a = (2 * j + 1 + len) * (2 * i + 1);
      sum += ((double) (src[j]) / 2147483648.0) * cos (a * phase);
}}
