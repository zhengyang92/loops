#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __int16_t int16_t;

int
fn (uint8_t new_cfhd_vlc_len[528], const uint8_t table_9_vlc_len[74], int i,
    uint32_t new_cfhd_vlc_bits[528], const uint32_t table_9_vlc_bits[74],
    int j, const uint16_t table_9_vlc_run[74],
    int16_t new_cfhd_vlc_level[528], const uint8_t table_9_vlc_level[74],
    uint16_t new_cfhd_vlc_run[528])
{
  IACA_START for (i = 0, j = 0; i < (71 + 3); i++, j++)
    {
      new_cfhd_vlc_bits[j] = table_9_vlc_bits[i];
      new_cfhd_vlc_len[j] = table_9_vlc_len[i];
      new_cfhd_vlc_run[j] = table_9_vlc_run[i];
      new_cfhd_vlc_level[j] = table_9_vlc_level[i];
      if (table_9_vlc_level[i]
	  && new_cfhd_vlc_bits[j] != table_9_vlc_bits[(71 + 3) - 1])
	{
	  new_cfhd_vlc_bits[j] <<= 1;
	  new_cfhd_vlc_len[j]++;
	  j++;
	  new_cfhd_vlc_bits[j] = (table_9_vlc_bits[i] << 1) | 1;
	  new_cfhd_vlc_len[j] = table_9_vlc_len[i] + 1;
	  new_cfhd_vlc_run[j] = table_9_vlc_run[i];
	  new_cfhd_vlc_level[j] = -table_9_vlc_level[i];
	}
     } IACA_END
}
