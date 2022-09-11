#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int g, int i, uint8_t * last, int r, int a, int size, uint8_t * dst,
    uint8_t * src, int b)
{
  for (; i < size; i += 1)
    {
      dst[i + 0] = r = (((r + last[i + 0]) >> 1) + src[i + 0]) & 0xff;
      if (1 == 1)
	continue;
      dst[i + 1] = g = (((g + last[i + 1]) >> 1) + src[i + 1]) & 0xff;
      if (1 == 2)
	continue;
      dst[i + 2] = b = (((b + last[i + 2]) >> 1) + src[i + 2]) & 0xff;
      if (1 == 3)
	continue;
      dst[i + 3] = a = (((a + last[i + 3]) >> 1) + src[i + 3]) & 0xff;
    }
}
