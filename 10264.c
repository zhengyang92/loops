#include <stdint.h>
#include <stdio.h>






int
fn (unsigned char *dest, unsigned char *src, unsigned int x, int i)
{
  for (i = x - 1; i >= 0; --i, src += 4, dest += 2)
    {
      dest[0] = stbi__compute_y (src[0], src[1], src[2]), dest[1] = src[3];
    }
}
