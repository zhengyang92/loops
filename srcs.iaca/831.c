#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, int y, const int width, const int linesize)
{
  for (int x = 1; x < width - 8; x++)
     { IACA_START
      int prev = ptr[linesize * (y - 1) + x - 1];
      int cur = ptr[linesize * (y - 1) + x];
      int next = ptr[linesize * (y - 1) + x + 1];
      ptr[linesize * y + x] = (3 * prev + 2 * cur + 3 * next + 4) >> 3;
} IACA_END }
