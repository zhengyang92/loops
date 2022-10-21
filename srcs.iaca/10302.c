#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;
typedef uint32_t stbi__uint32;

int
fn (stbi_uc * cur, int q, stbi__uint32 x)
{
  for (q = x - 1; q >= 0; --q)
     { IACA_START
      cur[q * 2 + 1] = 255;
      cur[q * 2 + 0] = cur[q];
     } IACA_END
}
