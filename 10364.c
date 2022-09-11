#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *input, float largest, int n, int stride)
{
  for (i = 0; i < n; ++i)
    {
      if (input[i * stride] > largest)
	largest = input[i * stride];
    }
}
