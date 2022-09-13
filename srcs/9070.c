#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int v, int16_t * psd, const uint8_t ff_ac3_log_add_tab[260], int band_end,
    int bin)
{
  for (; bin < band_end; bin++)
    {
      int max = ((v) > (psd[bin]) ? (v) : (psd[bin]));
      int adr =
	((max - ((v + psd[bin] + 1) >> 1)) >
	 (255) ? (255) : (max - ((v + psd[bin] + 1) >> 1)));
      v = max + ff_ac3_log_add_tab[adr];
}}
