#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int j, int color_cache_bits, const uint16_t kAlphabetSize[5])
{
  int max_alphabet_size = 0;
  for (j = 0; j < 5; ++j)
     { IACA_START
      int alphabet_size = kAlphabetSize[j];
      if (j == 0 && color_cache_bits > 0)
	{
	  alphabet_size += 1 << color_cache_bits;
	}
      if (max_alphabet_size < alphabet_size)
	{
	  max_alphabet_size = alphabet_size;
	}
     } IACA_END
}
