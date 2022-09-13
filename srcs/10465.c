#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;
typedef stbi__context;
typedef uint32_t stbi__uint32;

int
fn (stbi__uint32 i, stbi_uc palette[1024], stbi__context * s,
    stbi__uint32 pal_len)
{
  for (i = 0; i < pal_len; ++i)
    {
      palette[i * 4 + 0] = stbi__get8 (s);
      palette[i * 4 + 1] = stbi__get8 (s);
      palette[i * 4 + 2] = stbi__get8 (s);
      palette[i * 4 + 3] = 255;
    }
}
