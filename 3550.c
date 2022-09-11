#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t ve[11], const uint16_t * top, int i, uint16_t vo[11])
{
  for (i = 0; i < 8 - 1; i++)
    {
      ve[8 / 2 + i] = (top[i] + top[i + 1] + 1) >> 1;
      vo[8 / 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
    }
}
