#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * band, int j, int width)
{
  for (j = 1; j < width; j++)
    {
      band[j] += band[j - 1];
    }
}
