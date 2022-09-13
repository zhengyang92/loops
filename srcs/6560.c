#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int i, uint16_t scale_factor_modshift[64])
{
  for (i = 0; i < 64; i++)
    {
      int shift, mod;
      shift = i / 3;
      mod = i % 3;
      scale_factor_modshift[i] = mod | (shift << 2);
}}
