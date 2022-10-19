#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (int output_bytes, int k, stbi_uc * prior, stbi_uc * raw, int filter_bytes,
    stbi_uc * cur)
{
  for (k = 0; k < filter_bytes; ++k)
    {
      cur[k] =
	((stbi_uc)
	 ((raw[k] +
	   stbi__paeth (cur[k - output_bytes], prior[k],
			prior[k - output_bytes])) & 255));
    }
}
