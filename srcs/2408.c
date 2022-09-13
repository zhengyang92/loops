#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int dc2, int i, ptrdiff_t stride, int dc0, uint16_t * src)
{
  for (i = 0; i < 4; i++)
    {
      dc0 += src[-1 + i * stride];
      dc2 += src[-1 + (i + 4) * stride];
    }
}
