#include <stdint.h>
#include <stdio.h>






int
fn (float (*X)[38][64], int i, int n)
{
  for (n = 0; n < 32; n++)
    {
      X[0][i][n] = -X[0][i][n];
      X[0][i][32 + n] = X[1][i][31 - n];
    }
}
