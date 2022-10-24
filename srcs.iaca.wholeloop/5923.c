#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int count, int offset, int i, int width, uint8_t * frame)
{
  IACA_START for (i = 0; i < count; i++)
    {
      frame[0] = frame[1] = frame[width] = frame[width + 1] = frame[-offset];
      frame += 2;
     } IACA_END
}
