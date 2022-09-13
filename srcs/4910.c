#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int dc2, int i, int dc0, ptrdiff_t stride, uint8_t * src)
{
  for (i = 0; i < 4; i++)
    {
      dc0 += src[-1 + i * stride];
      dc2 += src[-1 + (i + 4) * stride];
    }
}