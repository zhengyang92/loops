#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int os, int in_bps, int ch, uint8_t ** out, int is, const uint8_t * in,
    int len, int channels)
{
  for (ch = 0; ch < channels; ch++)
    {
      const uint8_t *pi = in + ch * in_bps;
      uint8_t *po = out[ch];
      uint8_t *end = po + os * len;
      do
	{
	  *(int32_t *) po = (*(const uint8_t *) pi - 0x80) << 24;
	  pi += is;
	  po += os;
	}
      while (po < end);
    }
}
