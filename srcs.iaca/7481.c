#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * vptr, const uint8_t * uptr, const int width, int sum_u)
{
  int sum_v = 0;
  for (int x = 0; x < width; x++)
    {
      sum_u += uptr[x];
      sum_v += vptr[x];
}}
