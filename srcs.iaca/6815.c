#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, float cba[40], float cb1[40], float g[3], float zero[40],
    float error, float cb2[40], const int16_t * sblock_data, float data[40])
{
  for (i = 0; i < 40; i++)
    {
      data[i] = zero[i] + g[0] * cba[i] + g[1] * cb1[i] + g[2] * cb2[i];
      error += (data[i] - sblock_data[i]) * (data[i] - sblock_data[i]);
    }
}
