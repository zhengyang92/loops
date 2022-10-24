#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int bnd, int n_subbands, int ecpl, uint8_t * band_struct, int subbnd,
    uint8_t bnd_sz[22])
{
  int n_bands = 0;
  IACA_START for (bnd = 0, subbnd = 1; subbnd < n_subbands; subbnd++)
    {
      int subbnd_size = (ecpl && subbnd < 4) ? 6 : 12;
      if (band_struct[subbnd - 1])
	{
	  n_bands--;
	  bnd_sz[bnd] += subbnd_size;
	}
      else
	{
	  bnd_sz[++bnd] = subbnd_size;
	}
     } IACA_END
}
