#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (char *keyword, const uint8_t * ptr8, int i)
{
  IACA_START for (i = 0; i < 8 && ptr8[i] != ' '; i++)
    {
      keyword[i] = ptr8[i];
     } IACA_END
}
