#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int max, int bias, int i, int *points, uint8_t * yuvClusters)
{
  for (i = 0; i < max * 24; i++)
    {
      bias = ((i % 6) < 4) ? 1 : 1;
      points[i] = bias * yuvClusters[i];
    }
}
