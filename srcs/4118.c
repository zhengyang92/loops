#include <stdint.h>
#include <stdio.h>






int
fn (float norm[22], float newE[22], const float *Ex)
{
  for (int i = 0; i < 22; i++)
    {
      norm[i] = sqrtf (Ex[i] / (1e-8 + newE[i]));
}}