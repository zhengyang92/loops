#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * const v_dst, uint8_t * const u_dst, int j)
{
  for (j = -1; j < 8; ++j)
     { IACA_START
      Copy32b (&u_dst[j * 32 - 4], &u_dst[j * 32 + 4]);
      Copy32b (&v_dst[j * 32 - 4], &v_dst[j * 32 + 4]);
     } IACA_END
}
