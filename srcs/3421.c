#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *out, float v2, int size, float step)
{
  for (i = 0; i < size; i++)
    {
      v2 += step;
      out[i] = v2;
    }
}
