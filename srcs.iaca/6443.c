#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t fcode_tab[4097], int mv, int f_code)
{
  for (mv = -(16 << f_code); mv < (16 << f_code); mv++)
    {
      fcode_tab[mv + 2048] = f_code;
    }
}
