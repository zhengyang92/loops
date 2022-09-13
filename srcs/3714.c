#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (int bw2, int i, uint8_t * src, uint16_t * out)
{
  for (i = 0; i < bw2; i++)
    {
      out[i] ^= *((uint16_t *) src);
      src += 2;
    }
}
