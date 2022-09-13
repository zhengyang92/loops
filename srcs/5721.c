#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t ff_ac3_band_start_tab[51], int bin,
    uint8_t ff_ac3_bin_to_band_tab[253])
{
  int band = 0;
  for (band = 0; band < 50; band++)
    {
      int band_end = ff_ac3_band_start_tab[band + 1];
      while (bin < band_end)
	ff_ac3_bin_to_band_tab[bin++] = band;
    }
}
