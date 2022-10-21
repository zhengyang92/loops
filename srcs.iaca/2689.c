#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int mv, uint8_t fcode_tab[8193], int f_code)
{
  for (mv = -(16 << f_code); mv < (16 << f_code); mv++)
     { IACA_START
      fcode_tab[mv + 4096] = f_code;
     } IACA_END
}
