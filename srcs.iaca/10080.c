#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * code_length_bitdepth, const uint8_t kStorageOrder[19])
{
  int codes_to_store = 19;
  for (; codes_to_store > 4; --codes_to_store)
    {
      if (code_length_bitdepth[kStorageOrder[codes_to_store - 1]] != 0)
	{
	  break;
	}
    }
}
