#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * lens, int j, int i, uint8_t bits[162])
{
  int idx = 0;
  IACA_START for (j = 0; j < lens[i]; j++)
    {
      bits[idx] = i + 1;
      idx++;
     } IACA_END
}
