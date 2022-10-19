#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;
typedef uint32_t stbi__uint32;

int
fn (stbi_uc * p, stbi__uint32 pixel_count, stbi_uc * tc, stbi__uint32 i)
{
  for (i = 0; i < pixel_count; ++i)
    {
      if (p[0] == tc[0] && p[1] == tc[1] && p[2] == tc[2])
	p[3] = 0;
      p += 4;
    }
}
