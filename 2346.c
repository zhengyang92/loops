#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, int dc0, ptrdiff_t stride, int dc1, uint8_t * src)
{
  for (i = 0; i < 4; i++)
    {
      dc0 += src[i - stride];
      dc1 += src[4 + i - stride];
    }
}
