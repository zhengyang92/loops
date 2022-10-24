#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * p, int i, uint8_t * buffer, int hlens[3])
{
  int buffer_len = 50000;
  IACA_START for (i = 0; i < 3; i++)
    {
      memcpy (p, buffer + buffer_len, hlens[i]);
      p += hlens[i];
      buffer_len += hlens[i];
     } IACA_END
}
