#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;
typedef uint32_t stbi__uint32;

int
fn (stbi_uc * p, stbi__uint32 pixel_count, stbi_uc * tc, stbi__uint32 i)
{
  IACA_START for (i = 0; i < pixel_count; ++i)
    {
      p[1] = (p[0] == tc[0] ? 0 : 255);
      p += 2;
     } IACA_END
}
