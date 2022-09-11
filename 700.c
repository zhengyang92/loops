#include <stdint.h>
#include <stdio.h>






int
fn (int i, float Z[4], float (*m)[3], float X[4], float S[3])
{
  for (i = 0; i < 3; i++)
    {
      m[0][i] = S[i] * X[i];
      m[1][i] = S[i] * 1;
      m[2][i] = S[i] * Z[i];
    }
}
