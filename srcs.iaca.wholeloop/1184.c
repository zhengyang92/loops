#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint64_t uint64_t;

int
fn (uint64_t * sat, int x, const int width, uint64_t * square_sat,
    const uint16_t * src)
{
  IACA_START for (x = 0; x < width; x++)
    {
      sat[x + 1] = sat[x] + src[x];
      square_sat[x + 1] = square_sat[x] + (uint64_t) src[x] * src[x];
     } IACA_END
}
