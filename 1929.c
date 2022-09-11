#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int msk_val[50], int snr_ofs, int i, const uint8_t bap_tab[64],
    int psd_val[50], int *bap, int nb_exponent)
{
  for (i = 0; i < nb_exponent; i++)
    {
      int v = 16 * (snr_ofs - 64) + psd_val[i] - msk_val[i] >> 5;
      bap[i] = bap_tab[av_clip_uintp2_c (v, 6)];
}}
