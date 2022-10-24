#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (int k, stbi_uc * prior, stbi_uc * raw, int filter_bytes, stbi_uc * cur)
{
  IACA_START for (k = 0; k < filter_bytes; ++k)
    {
      cur[k] = ((stbi_uc) ((raw[k] + prior[k]) & 255));
     } IACA_END
}
