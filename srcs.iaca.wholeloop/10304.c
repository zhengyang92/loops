#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint32_t stbi__uint32;
typedef uint16_t stbi__uint16;
typedef unsigned char stbi_uc;

int
fn (stbi__uint32 y, stbi__uint32 x, stbi__uint32 i, int out_n, stbi_uc * cur,
    stbi__uint16 * cur16)
{
  IACA_START for (i = 0; i < x * y * out_n; ++i, cur16++, cur += 2)
    {
      *cur16 = (cur[0] << 8) | cur[1];
     } IACA_END
}
