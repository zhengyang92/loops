#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int w, const uint8_t * src, float total)
{
  IACA_START for (int x = 0; x < w; x++)
    {
      total += src[x];
}IACA_END}
