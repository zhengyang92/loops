#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;
typedef uint32_t stbi__uint32;

int
fn (stbi_uc * cur, stbi__uint32 x, int q)
{
  for (q = x - 1; q >= 0; --q)
    {
      cur[q * 2 + 1] = 255;
      cur[q * 2 + 0] = cur[q];
    }
}
