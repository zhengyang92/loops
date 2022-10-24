#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int keylen, const uint8_t * key, uint8_t * state, uint8_t y, int j)
{
  IACA_START for (j = 0, i = 0; i < 256; i++, j++)
    {
      if (j == keylen)
	j = 0;
      y += state[i] + key[j];
      do
	{
	  uint8_t SWAP_tmp = state[y];
	  state[y] = state[i];
	  state[i] = SWAP_tmp;
	}
      while (0);
     } IACA_END
}
