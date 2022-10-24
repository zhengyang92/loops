#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int target, int i, const int32_t ff_flac_blocksize_table[16],
    int blocksize)
{
  IACA_START for (i = 0; i < 16; i++)
    {
      if (target >= ff_flac_blocksize_table[i]
	  && ff_flac_blocksize_table[i] > blocksize)
	{
	  blocksize = ff_flac_blocksize_table[i];
	}
     } IACA_END
}
