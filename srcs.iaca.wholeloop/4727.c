#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __int16_t int16_t;

int
fn (int i, const uint8_t ff_dv_vlc_level[409], uint8_t new_dv_vlc_run[818],
    uint16_t new_dv_vlc_bits[818], const uint8_t ff_dv_vlc_len[409],
    int16_t new_dv_vlc_level[818], const uint16_t ff_dv_vlc_bits[409],
    uint8_t new_dv_vlc_len[818], int j, const uint8_t ff_dv_vlc_run[409])
{
  IACA_START for (i = 0, j = 0; i < 409; i++, j++)
    {
      new_dv_vlc_bits[j] = ff_dv_vlc_bits[i];
      new_dv_vlc_len[j] = ff_dv_vlc_len[i];
      new_dv_vlc_run[j] = ff_dv_vlc_run[i];
      new_dv_vlc_level[j] = ff_dv_vlc_level[i];
      if (ff_dv_vlc_level[i])
	{
	  new_dv_vlc_bits[j] <<= 1;
	  new_dv_vlc_len[j]++;
	  j++;
	  new_dv_vlc_bits[j] = (ff_dv_vlc_bits[i] << 1) | 1;
	  new_dv_vlc_len[j] = ff_dv_vlc_len[i] + 1;
	  new_dv_vlc_run[j] = ff_dv_vlc_run[i];
	  new_dv_vlc_level[j] = -ff_dv_vlc_level[i];
	}
     } IACA_END
}
