#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (stbi_uc * cur, int k, stbi_uc * raw, int filter_bytes)
{
  IACA_START for (k = 0; k < filter_bytes; ++k)
    {
      cur[k] = raw[k];
     } IACA_END
}
