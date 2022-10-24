#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int mv, uint8_t umv_fcode_tab[8193])
{
  IACA_START for (mv = 0; mv < 4096 * 2 + 1; mv++)
    {
      umv_fcode_tab[mv] = 1;
     } IACA_END
}
