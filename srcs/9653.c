#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int os, int in_bps, int ch, int is, uint8_t ** out, const uint8_t * in,
    int len, int channels)
{
  for (ch = 0; ch < channels; ch++)
    {
      const uint8_t *pi = in + ch * in_bps;
      uint8_t *po = out[ch];
      uint8_t *end = po + os * len;
      do
	{
	  *(float *) po = (*(const uint8_t *) pi - 0x80) * (1.0f / (1 << 7));
	  pi += is;
	  po += os;
	}
      while (po < end);
    }
}
