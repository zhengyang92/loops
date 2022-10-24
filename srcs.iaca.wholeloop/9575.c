#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint8_t uint8_t;

int
fn (uint64_t * counts, int i, int width, uint8_t * src)
{
  IACA_START for (i = 0; i < width; i++)
    {
      counts[src[i]]++;
     } IACA_END
}
