#include <stdint.h>
#include <stdio.h>




typedef uint16_t stbi__uint16;

int
fn (stbi__uint16 * dest, stbi__uint16 * src, unsigned int x, int i)
{
  for (i = x - 1; i >= 0; --i, src += 2, dest += 3)
    {
      dest[0] = dest[1] = dest[2] = src[0];
    }
}
