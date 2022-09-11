#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * top, uint8_t ve[47], int i, uint8_t vo[47])
{
  for (i = 0; i < 32 - 1; i++)
    {
      ve[32 / 2 + i] = (top[i] + top[i + 1] + 1) >> 1;
      vo[32 / 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
    }
}
