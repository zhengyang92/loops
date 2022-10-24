#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int y, const int linesize, int x, const int depth, const uint16_t fill,
    const int start_left, uint16_t * ptr)
{
  IACA_START for (x = 0; x < start_left; x++)
    {
      int src = ptr[y * linesize + x];
      ptr[y * linesize + x] =
	lerp16 (fill, src, start_left - x, start_left, depth);
}IACA_END}
