#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * src, const int w, float total)
{
  IACA_START for (int x = 0; x < w; x++)
    {
      total += src[x];
}IACA_END}
