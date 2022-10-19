#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int *p2, int16_t predictors[256], int i, int *p1, int j)
{
  for (j = 0; j < (i + 1) / 2; j++)
    {
      int tmp = *p1 + (predictors[i] * *p2 + 256 >> 9);
      *p2 = *p2 + (predictors[i] * *p1 + 256 >> 9);
      *p1 = tmp;
      p1++;
      p2--;
}}
