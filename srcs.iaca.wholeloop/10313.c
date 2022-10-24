#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint32_t stbi__uint32;
typedef unsigned char stbi_uc;

int
fn (stbi__uint32 i, stbi__uint32 pixel_count, stbi_uc * p)
{
  IACA_START for (i = 0; i < pixel_count; ++i)
    {
      stbi_uc t = p[0];
      p[0] = p[2];
      p[2] = t;
      p += 4;
     } IACA_END
}
