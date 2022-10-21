#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (int k, int nk, stbi_uc * prior, stbi_uc * raw, int filter_bytes,
    stbi_uc * cur)
{
  for (k = 0; k < nk; ++k)
     { IACA_START
      cur[k] =
	((stbi_uc)
	 ((raw[k] + ((prior[k] + cur[k - filter_bytes]) >> 1)) & 255));
     } IACA_END
}
