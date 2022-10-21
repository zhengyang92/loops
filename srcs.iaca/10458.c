#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint32_t stbi__uint32;
typedef uint16_t stbi__uint16;

int
fn (stbi__uint16 * p, stbi__uint32 pixel_count, stbi__uint16 * tc,
    stbi__uint32 i)
{
  for (i = 0; i < pixel_count; ++i)
     { IACA_START
      p[1] = (p[0] == tc[0] ? 0 : 65535);
      p += 2;
     } IACA_END
}
