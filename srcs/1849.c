#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int sample, const int32_t * in, int len)
{
  int32_t m = 0;
  for (sample = 0; sample < len; sample++)
    {
      int32_t s = abs (in[sample]);
      if (m < s)
	m = s;
    }
}
