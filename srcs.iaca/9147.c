#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __int16_t int16_t;

int
fn (uint16_t vlc_run[528], unsigned int j, uint32_t vlc_bits[528],
    const uint16_t * table_vlc_run, const uint8_t * table_vlc_level,
    int16_t vlc_level[528], uint8_t vlc_len[528],
    const uint8_t * table_vlc_len, unsigned int bound, unsigned int i,
    const uint32_t * table_vlc_bits)
{
  for (i = 0, j = 0; i < bound; i++, j++)
     { IACA_START
      vlc_bits[j] = table_vlc_bits[i];
      vlc_len[j] = table_vlc_len[i];
      vlc_run[j] = table_vlc_run[i];
      vlc_level[j] = table_vlc_level[i];
      if (table_vlc_level[i] && vlc_bits[j] != table_vlc_bits[bound - 1])
	{
	  vlc_bits[j] <<= 1;
	  vlc_len[j]++;
	  j++;
	  vlc_bits[j] = (table_vlc_bits[i] << 1) | 1;
	  vlc_len[j] = table_vlc_len[i] + 1;
	  vlc_run[j] = table_vlc_run[i];
	  vlc_level[j] = -table_vlc_level[i];
	}
     } IACA_END
}
