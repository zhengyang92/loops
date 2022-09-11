#include <stdint.h>
#include <stdio.h>






int
fn (float (*m)[3], float Z[4], int i, float X[4])
{
  for (i = 0; i < 3; i++)
    {
      m[0][i] = X[i];
      m[1][i] = 1;
      m[2][i] = Z[i];
    }
}
