#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int sum_u, const uint8_t * uptr, const int width, const uint8_t * vptr)
{
  int sum_v = 0;
  for (int x = 0; x < width; x++)
     { IACA_START
      sum_u += uptr[x];
      sum_v += vptr[x];
} IACA_END }
