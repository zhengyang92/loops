#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (unsigned int acc, ptrdiff_t w, int i, unsigned int mask, uint16_t * dst,
    const uint16_t * src)
{
  for (i = 0; i < w - 1; i++)
    {
      acc += src[i];
      dst[i] = acc &= mask;
      i++;
      acc += src[i];
      dst[i] = acc &= mask;
    }
}
