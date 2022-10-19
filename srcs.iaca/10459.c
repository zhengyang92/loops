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
    {
      if (p[0] == tc[0] && p[1] == tc[1] && p[2] == tc[2])
	p[3] = 0;
      p += 4;
    }
}
