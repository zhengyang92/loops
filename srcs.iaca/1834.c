#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int dca_mask, int dca_ch, const uint8_t * dca2wav, int wav_ch,
    int wav_map[18])
{
  int wav_mask = 0;
  for (dca_ch = 0; dca_ch < 28; dca_ch++)
    {
      if (dca_mask & (1 << dca_ch))
	{
	  wav_ch = dca2wav[dca_ch];
	  if (!(wav_mask & (1 << wav_ch)))
	    {
	      wav_map[wav_ch] = dca_ch;
	      wav_mask |= 1 << wav_ch;
	    }
	}
    }
}
