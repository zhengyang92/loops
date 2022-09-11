#include <stdint.h>
#include <stdio.h>






int
fn (int j, float (*in)[2], const float *filter)
{
  float im_op = 0.0f;
  float re_op = 0.0f;
  for (j = 0; j < 6; j += 2)
    {
      re_op += filter[j + 1] * (in[j + 1][0] + in[12 - j - 1][0]);
      im_op += filter[j + 1] * (in[j + 1][1] + in[12 - j - 1][1]);
    }
}
