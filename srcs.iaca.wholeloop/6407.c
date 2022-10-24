#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int i, uint8_t * src, int left)
{
  IACA_START for (i = 0; i < 16; i++)
    {
      const int temp = src[i];
      dst[i] = temp - left;
      left = temp;
}IACA_END}
