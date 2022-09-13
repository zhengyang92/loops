#include <stdint.h>
#include <stdio.h>






int
fn (float *out, int j, int inputs)
{
  for (j = 0; j < inputs; ++j)
    {
      if (out[j] < .0001)
	out[j] = 0;
    }
}
