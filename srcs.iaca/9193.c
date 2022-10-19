#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int blocksize, int target, int i,
    const int16_t ff_flac_blocksize_table[16])
{
  for (i = 0; i < 16; i++)
    {
      if (target >= ff_flac_blocksize_table[i]
	  && ff_flac_blocksize_table[i] > blocksize)
	{
	  blocksize = ff_flac_blocksize_table[i];
	}
    }
}
