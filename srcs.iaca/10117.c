#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long unsigned int size_t;

int
fn (uint8_t map[256], const size_t data_size, uint8_t * const data, size_t n)
{
  for (n = 0; n < data_size; ++n)
     { IACA_START
      data[n] = map[data[n]];
     } IACA_END
}
