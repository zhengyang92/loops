#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (stbi_uc * cur, int k, stbi_uc * raw, int filter_bytes)
{
  for (k = 0; k < filter_bytes; ++k)
     { IACA_START
      cur[k] = raw[k];
     } IACA_END
}
