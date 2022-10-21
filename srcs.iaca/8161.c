#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint8_t uint8_t;

int
fn (int width, uint8_t * src, uint64_t * counts, int i)
{
  for (i = 0; i < width; i++)
     { IACA_START
      counts[src[i]]++;
     } IACA_END
}
