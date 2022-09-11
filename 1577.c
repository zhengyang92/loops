#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t ** matrix, int in_ch, int j, int v0, int16_t ** samples,
    int v1)
{
  for (j = 0; j < in_ch; j++)
    {
      v0 += samples[j][i] * matrix[0][j];
      v1 += samples[j][i] * matrix[1][j];
    }
}
