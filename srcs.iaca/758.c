#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int n, int i, double (*matrix)[3], double *h)
{
  for (i = 1; i < n - 1; i++)
    {
      matrix[i][0] = h[i - 1];
      matrix[i][1] = 2 * (h[i - 1] + h[i]);
      matrix[i][2] = h[i];
    }
}
