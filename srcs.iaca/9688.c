#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int in_bps, int ch, uint8_t ** out, int is, const uint8_t * in, int len,
    int channels, int os)
{
  for (ch = 0; ch < channels; ch++)
     { IACA_START
      const uint8_t *pi = in + ch * in_bps;
      uint8_t *po = out[ch];
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
