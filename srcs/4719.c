#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int msk_val[50], int i, const uint16_t * fast_decay, int slow_decay,
    const uint16_t * slow_gain, int fast_gain, int psd_val[50],
    const uint16_t * fast_gain_adj, int nb_exponent)
{
  int fast_leak = 0;
  int slow_leak = 0;
  for (i = 0; i < nb_exponent; i++)
    {
      fast_leak =
	log_add (fast_leak - fast_decay[i],
		 psd_val[i] - fast_gain + fast_gain_adj[i]);
      slow_leak = log_add (slow_leak - slow_decay, psd_val[i] - slow_gain[i]);
      msk_val[i] = ((fast_leak) > (slow_leak) ? (fast_leak) : (slow_leak));
    }
}
