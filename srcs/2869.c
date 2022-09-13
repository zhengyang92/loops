#include <stdint.h>
#include <stdio.h>






int
fn (double pow43_lut[16], int value, double exp2_val, int exponent,
    float expval_table_float[512][16])
{
  for (value = 0; value < 16; value++)
    {
      double f = pow43_lut[value] * exp2_val;
      expval_table_float[exponent][value] = f;
}}
