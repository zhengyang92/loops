#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint16_t uint16_t;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t new_cfhd_vlc_level[528], uint8_t new_cfhd_vlc_len[528], int i,
    uint32_t new_cfhd_vlc_bits[528], const uint16_t table_18_vlc_run[264],
    const uint8_t table_18_vlc_len[264],
    const uint32_t table_18_vlc_bits[264],
    const uint8_t table_18_vlc_level[264], int j,
    uint16_t new_cfhd_vlc_run[528])
{
  IACA_START for (i = 0, j = 0; i < (263 + 1); i++, j++)
    {
      new_cfhd_vlc_bits[j] = table_18_vlc_bits[i];
      new_cfhd_vlc_len[j] = table_18_vlc_len[i];
      new_cfhd_vlc_run[j] = table_18_vlc_run[i];
      new_cfhd_vlc_level[j] = table_18_vlc_level[i];
      if (table_18_vlc_level[i]
	  && new_cfhd_vlc_bits[j] != table_18_vlc_bits[(263 + 1) - 1])
	{
	  new_cfhd_vlc_bits[j] <<= 1;
	  new_cfhd_vlc_len[j]++;
	  j++;
	  new_cfhd_vlc_bits[j] = (table_18_vlc_bits[i] << 1) | 1;
	  new_cfhd_vlc_len[j] = table_18_vlc_len[i] + 1;
	  new_cfhd_vlc_run[j] = table_18_vlc_run[i];
	  new_cfhd_vlc_level[j] = -table_18_vlc_level[i];
	}
     } IACA_END
}
