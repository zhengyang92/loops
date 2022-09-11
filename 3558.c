#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t ve[7], int i, const uint16_t * top, uint16_t vo[7])
{
  for (i = 0; i < 8 - 2; i++)
    {
      ve[i] = (top[i] + top[i + 1] + 1) >> 1;
      vo[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    }
}
