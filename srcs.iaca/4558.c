#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (const uint8_t gain_mode[4][3], uint8_t ad, uint8_t adjust_num, uint8_t wd,
    const int mode, GetBitContext * gb)
{
  for (ad = 0; ad < adjust_num; ad++)
     { IACA_START
      skip_bits (gb,
		 4 +
		 ((wd == 0 && gain_mode[mode][1]) ? 4 : gain_mode[mode][2]));
     } IACA_END
}
