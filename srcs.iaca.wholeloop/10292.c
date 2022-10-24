#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (int k, int nk, stbi_uc * raw, int filter_bytes, stbi_uc * cur)
{
  IACA_START for (k = 0; k < nk; ++k)
    {
      cur[k] = ((stbi_uc) ((raw[k] + (cur[k - filter_bytes] >> 1)) & 255));
     } IACA_END
}
