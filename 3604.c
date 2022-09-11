#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * top, const uint8_t * left, int i, uint8_t v[46])
{
  for (i = 0; i < 16 - 2; i++)
    {
      v[i * 2] = (left[i + 1] + left[i + 0] + 1) >> 1;
      v[i * 2 + 1] = (left[i + 2] + left[i + 1] * 2 + left[i + 0] + 2) >> 2;
      v[16 * 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
    }
}
