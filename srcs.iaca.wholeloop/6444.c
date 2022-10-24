#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t umv_fcode_tab[4097], int mv)
{
  IACA_START for (mv = 0; mv < 2048 * 2 + 1; mv++)
    {
      umv_fcode_tab[mv] = 1;
     } IACA_END
}
