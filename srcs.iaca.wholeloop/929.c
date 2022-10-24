#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * uptr, const int half, const int width, uint16_t * vptr)
{
  IACA_START for (int x = 0; x < width; x++)
    {
      uptr[x] = half;
      vptr[x] = half;
}IACA_END}
