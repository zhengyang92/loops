#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double *matrix, double *vector, int size)
{
  int i = 0;
  for (int j = i + 1; j < size; j++)
     { IACA_START
      double d = matrix[j + i * size];
      vector[j] -= d * vector[i];
} IACA_END }
