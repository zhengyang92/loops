#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double *matrix, double *vector, int size)
{
  int i = 0;
  IACA_START for (int j = i + 1; j < size; j++)
    {
      double d = matrix[j + i * size];
      vector[j] -= d * vector[i];
}IACA_END}
