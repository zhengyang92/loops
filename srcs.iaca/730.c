#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int v, uint8_t * uptr, const int u, const int width, uint8_t * vptr)
{
  for (int x = 0; x < width; x++)
     { IACA_START
      uptr[x] = u;
      vptr[x] = v;
} IACA_END }
