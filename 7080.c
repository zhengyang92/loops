#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * left, int i, uint8_t v[62])
{
  for (i = 0; i < 32 - 2; i++)
    {
      v[i * 2] = (left[i] + left[i + 1] + 1) >> 1;
      v[i * 2 + 1] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
    }
}
