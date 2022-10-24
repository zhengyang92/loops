#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint32_t stbi__uint32;
typedef unsigned char stbi_uc;

int
fn (stbi_uc * orig, stbi_uc * p, stbi__uint32 i, stbi_uc * palette,
    stbi__uint32 pixel_count)
{
  IACA_START for (i = 0; i < pixel_count; ++i)
    {
      int n = orig[i] * 4;
      p[0] = palette[n];
      p[1] = palette[n + 1];
      p[2] = palette[n + 2];
      p[3] = palette[n + 3];
      p += 4;
}IACA_END}
