#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t ve[31], const uint8_t * top, uint8_t vo[31], int i)
{
  for (i = 0; i < 32 - 2; i++)
    {
      ve[i] = (top[i] + top[i + 1] + 1) >> 1;
      vo[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    }
}
