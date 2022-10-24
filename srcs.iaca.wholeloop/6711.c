#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;
typedef __int32_t int32_t;

int
fn (const int16_t silk_cosine[129], int32_t lsp[16],
    const uint8_t silk_lsf_ordering_nbmb[10], int k,
    const uint8_t silk_lsf_ordering_wb[16], const int16_t * nlsf, int order)
{
  IACA_START for (k = 0; k < order; k++)
    {
      int index = nlsf[k] >> 8;
      int offset = nlsf[k] & 255;
      int k2 =
	(order == 10) ? silk_lsf_ordering_nbmb[k] : silk_lsf_ordering_wb[k];
      lsp[k2] = silk_cosine[index] * 256;
      lsp[k2] += (silk_cosine[index + 1] - silk_cosine[index]) * offset;
      lsp[k2] = (lsp[k2] + 4) >> 3;
}IACA_END}
