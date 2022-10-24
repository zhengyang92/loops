#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int i, int min_width, uint16_t * dst16, const uint16_t * src16, int left)
{
  IACA_START for (i = 0; i < min_width; i++)
    {
      const int temp = src16[i];
      dst16[i] = temp - left;
      left = temp;
}IACA_END}
