#include <stdint.h>
#include <stdio.h>






int
fn (int channels, double max, double *buf, int c)
{
  for (c = 0; c < channels; c++)
    {
      max = fabs (buf[c]) > max ? fabs (buf[c]) : max;
    }
}
