#include <stdint.h>
#include <stdio.h>






int
fn (int cut, int count, int x, double *values, double mean)
{
  for (x = cut; x < count - cut; x++)
    {
      mean += values[x];
    }
}
