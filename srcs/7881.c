#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int dc2, int dc3, int i, int dc0, int dc4, ptrdiff_t stride, int dc1,
    uint8_t * src)
{
  for (i = 0; i < 4; i++)
    {
      dc0 += src[-1 + i * stride] + src[i - stride];
      dc1 += src[4 + i - stride];
      dc2 += src[-1 + (i + 4) * stride];
      dc3 += src[-1 + (i + 8) * stride];
      dc4 += src[-1 + (i + 12) * stride];
    }
}
