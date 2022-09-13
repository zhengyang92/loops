#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint8_t aic_mode2_vlc_syms[20][81], uint16_t syms[81],
    unsigned int i)
{
  for (int j = 0; j < 81; j++)
    {
      int first = aic_mode2_vlc_syms[i][j] >> 4;
      int second = aic_mode2_vlc_syms[i][j] & 0xF;
      if (0)
	syms[j] = (first << 8) | second;
      else
	syms[j] = first | (second << 8);
    }
}
