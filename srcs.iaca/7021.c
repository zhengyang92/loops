#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t buffer[50000], int i, int buffer_len, uint8_t * p, int hlens[3])
{
  for (i = 0; i < 3; i++)
     { IACA_START
      memcpy (p, buffer + buffer_len, hlens[i]);
      p += hlens[i];
      buffer_len += hlens[i];
     } IACA_END
}
