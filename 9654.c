#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int os, int ch, const uint8_t ** in, int is, int out_bps, int len,
    int channels, uint8_t * out)
{
  for (ch = 0; ch < channels; ch++)
    {
      const uint8_t *pi = in[ch];
      uint8_t *po = out + ch * out_bps;
      uint8_t *end = po + os * len;
      do
	{
	  *(double *) po = (*(const uint8_t *) pi - 0x80) * (1.0 / (1 << 7));
	  pi += is;
	  po += os;
	}
      while (po < end);
    }
}
