#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int ch, int is, const uint8_t ** in, int out_bps, int len, int channels,
    int os, uint8_t * out)
{
  IACA_START for (ch = 0; ch < channels; ch++)
    {
      const uint8_t *pi = in[ch];
      uint8_t *po = out + ch * out_bps;
      uint8_t *end = po + os * len;
      do
	{
	  *(double *) po = *(const double *) pi;
	  pi += is;
	  po += os;
	}
      while (po < end);
     } IACA_END
}
