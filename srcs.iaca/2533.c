#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;
typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int8_t (*out)[64], const int8_t Gaussian_LUT[2052], const uint8_t freq_h,
    uint32_t seed)
{
  int y = 0;
  for (int x = 0; x <= freq_h; x += 4)
    {
      uint16_t offset = seed % 2048;
      out[x + 0][y] = Gaussian_LUT[offset + 0];
      out[x + 1][y] = Gaussian_LUT[offset + 1];
      out[x + 2][y] = Gaussian_LUT[offset + 2];
      out[x + 3][y] = Gaussian_LUT[offset + 3];
      prng_shift (&seed);
}}
