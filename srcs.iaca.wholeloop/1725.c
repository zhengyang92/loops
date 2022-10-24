#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;
typedef __uint64_t uint64_t;

int
fn (int y, uint64_t a, ptrdiff_t stride, uint8_t * left, uint8_t * d)
{
  IACA_START for (y = 0; y < 8; y++)
    {
      a = left[y + 1] * 0x0101010101010101ULL;
      *((uint64_t *) (d + y * stride)) = a;
     } IACA_END
}
