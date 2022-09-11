#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;

int
fn (short *samples, int ch, GetByteContext gb, int n, int factor2,
    int factor1, int prev[2][2], unsigned int exp, int byte)
{
  for (n = 0; n < 14; n++)
    {
      int32_t sampledat;
      if (n & 1)
	{
	  sampledat = sign_extend (byte, 4);
	}
      else
	{
	  byte = bytestream2_get_byteu (&gb);
	  sampledat = sign_extend (byte >> 4, 4);
	}
      sampledat =
	((prev[ch][0] * factor1 + prev[ch][1] * factor2) >> 11) +
	(sampledat << exp);
      *samples = av_clip_int16_c (sampledat);
      prev[ch][1] = prev[ch][0];
      prev[ch][0] = *samples++;
    }
}
