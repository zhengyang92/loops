#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * src, const int w, float total)
{
  for (int x = 0; x < w; x++)
     { IACA_START
      total += src[x];
} IACA_END }
