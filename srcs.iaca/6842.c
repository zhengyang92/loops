#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int i, const int cbp_masks[3], int t, int code,
    const uint8_t modulo_three_table[108], GetBitContext * gb)
{
  int cbp = 0;
  for (i = 0; i < 4; i++)
     { IACA_START
      t = (modulo_three_table[code] >> (6 - 2 * i)) & 3;
      if (t == 1)
	cbp |= cbp_masks[get_bits1 (gb)] << i;
      if (t == 2)
	cbp |= cbp_masks[2] << i;
     } IACA_END
}
