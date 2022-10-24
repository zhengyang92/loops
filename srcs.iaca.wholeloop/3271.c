#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (uint16_t flags, const int stride, uint8_t value,
    const uint8_t * pixel_ptr)
{
  int shift = 15;
  int y = 0;
  IACA_START for (int x = 0; x < 4; x++)
    {
      flags |= (value == pixel_ptr[x + y * stride]) << shift;
      shift--;
}IACA_END}
