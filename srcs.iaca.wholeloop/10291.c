#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (int k, int nk, stbi_uc * prior, stbi_uc * raw, int filter_bytes,
    stbi_uc * cur)
{
  IACA_START for (k = 0; k < nk; ++k)
    {
      cur[k] =
	((stbi_uc)
	 ((raw[k] +
	   stbi__paeth (cur[k - filter_bytes], prior[k],
			prior[k - filter_bytes])) & 255));
     } IACA_END
}
