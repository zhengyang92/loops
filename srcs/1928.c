#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int msk_val[50], int misc_decay, int i, const uint8_t band_low_tab[3],
    int fast_gain, int psd_val[50], int nb_code, int nb_exponent)
{
  int fast_leak = 0;
  for (i = nb_exponent - 1; i > band_low_tab[nb_code]; i--)
    {
      fast_leak = log_add (fast_leak - misc_decay, psd_val[i] - fast_gain);
      msk_val[i] = ((msk_val[i]) > (fast_leak) ? (msk_val[i]) : (fast_leak));
    }
}
