#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint32_t stbi__uint32;
typedef unsigned char stbi_uc;

int
fn (stbi__uint32 x, int output_bytes, stbi__uint32 i, int filter_bytes,
    stbi_uc * cur)
{
  for (i = 0; i < x; ++i, cur += output_bytes)
     { IACA_START
      cur[filter_bytes + 1] = 255;
     } IACA_END
}
