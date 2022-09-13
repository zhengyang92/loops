#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int bias, int i, uint8_t * yuvClusters, int *points, int max)
{
  for (i = 0; i < max * 24; i++)
    {
      bias = ((i % 6) < 4) ? 1 : 1;
      points[i] = bias * yuvClusters[i];
    }
}
