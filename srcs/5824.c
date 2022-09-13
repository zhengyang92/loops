#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t binkb_den[16], double s[64],
    int32_t binkb_inter_quant[16][64], int i, uint8_t inv_bink_scan[64],
    int32_t binkb_intra_quant[16][64], const uint8_t binkb_intra_seed[64],
    const uint8_t binkb_inter_seed[64], int j, const uint8_t binkb_num[16])
{
  for (i = 0; i < 64; i++)
    {
      int k = inv_bink_scan[i];
      if (s[i] == 1.0)
	{
	  binkb_intra_quant[j][k] =
	    (1L << 12) * binkb_intra_seed[i] * binkb_num[j] / binkb_den[j];
	  binkb_inter_quant[j][k] =
	    (1L << 12) * binkb_inter_seed[i] * binkb_num[j] / binkb_den[j];
	}
      else
	{
	  binkb_intra_quant[j][k] =
	    (1L << 12) * binkb_intra_seed[i] * s[i] * binkb_num[j] /
	    (double) binkb_den[j];
	  binkb_inter_quant[j][k] =
	    (1L << 12) * binkb_inter_seed[i] * s[i] * binkb_num[j] /
	    (double) binkb_den[j];
}}}
