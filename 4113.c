#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexFloat
{
  float re, im;
} AVComplexFloat;
typedef __uint8_t uint8_t;

int
fn (float sum[22], const uint8_t eband5ms[22], int band_size,
    const AVComplexFloat * X)
{
  int i = 0;
  for (int j = 0; j < band_size; j++)
    {
      float tmp, frac = (float) j / band_size;
      tmp = ((X[(eband5ms[i] << 2) + j].re) * (X[(eband5ms[i] << 2) + j].re));
      tmp +=
	((X[(eband5ms[i] << 2) + j].im) * (X[(eband5ms[i] << 2) + j].im));
      sum[i] += (1.f - frac) * tmp;
      sum[i + 1] += frac * tmp;
}}
