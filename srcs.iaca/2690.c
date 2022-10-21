#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int mv, uint8_t umv_fcode_tab[8193])
{
  for (mv = 0; mv < 4096 * 2 + 1; mv++)
     { IACA_START
      umv_fcode_tab[mv] = 1;
     } IACA_END
}
