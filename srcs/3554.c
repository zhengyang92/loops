#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t vo[47], uint16_t ve[47], int i, const uint16_t * top)
{
  for (i = 0; i < 32 - 1; i++)
    {
      ve[32 / 2 + i] = (top[i] + top[i + 1] + 1) >> 1;
      vo[32 / 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
    }
}
