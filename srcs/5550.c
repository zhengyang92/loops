#include <stdint.h>
#include <stdio.h>




typedef float TXSample;
typedef long int ptrdiff_t;

int
fn (TXSample * dst, int len2, ptrdiff_t stride, int len4, int len)
{
  for (int i = 0; i < len4; i++)
    {
      dst[i * stride] = -dst[(len2 - i - 1) * stride];
      dst[(len - i - 1) * stride] = dst[(len2 + i + 0) * stride];
}}
