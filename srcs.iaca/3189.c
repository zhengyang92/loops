#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (unsigned int i, uint16_t syms[81],
    const uint8_t aic_mode2_vlc_syms[20][81])
{
  for (int j = 0; j < 81; j++)
     { IACA_START
      int first = aic_mode2_vlc_syms[i][j] >> 4;
      int second = aic_mode2_vlc_syms[i][j] & 0xF;
      if (0)
	syms[j] = (first << 8) | second;
      else
	syms[j] = first | (second << 8);
     } IACA_END
}
