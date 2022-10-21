#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int os, int ch, const uint8_t ** in, int out_bps, int is, int len,
    int channels, uint8_t * out)
{
  for (ch = 0; ch < channels; ch++)
     { IACA_START
      const uint8_t *pi = in[ch];
      uint8_t *po = out + ch * out_bps;
      uint8_t *end = po + os * len;
      do
	{
	  *(float *) po = *(const double *) pi;
	  pi += is;
	  po += os;
	}
      while (po < end);
     } IACA_END
}
