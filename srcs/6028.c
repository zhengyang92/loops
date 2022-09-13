#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int j, int16_t * lpc, const int16_t cos_tab[513])
{
  for (j = 0; j < 10; j++)
    {
      int index = (lpc[j] >> 7) & 0x1FF;
      int offset = lpc[j] & 0x7f;
      int temp1 = cos_tab[index] << 16;
      int temp2 =
	(cos_tab[index + 1] - cos_tab[index]) * ((offset << 8) + 0x80) << 1;
      lpc[j] = -(av_sat_dadd32_c (1 << 15, temp1 + temp2) >> 16);
}}
