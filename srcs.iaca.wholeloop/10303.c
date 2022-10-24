#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;
typedef uint32_t stbi__uint32;

int
fn (stbi_uc * cur, int q, stbi__uint32 x)
{
  IACA_START for (q = x - 1; q >= 0; --q)
    {
      cur[q * 4 + 3] = 255;
      cur[q * 4 + 2] = cur[q * 3 + 2];
      cur[q * 4 + 1] = cur[q * 3 + 1];
      cur[q * 4 + 0] = cur[q * 3 + 0];
     } IACA_END
}
