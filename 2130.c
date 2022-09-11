#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * quantizer_output, int j, int i, const uint8_t min_distance[2])
{
  for (i = 1; i < 10; i++)
    {
      int diff =
	(quantizer_output[i - 1] - quantizer_output[i] +
	 min_distance[j]) >> 1;
      if (diff > 0)
	{
	  quantizer_output[i - 1] -= diff;
	  quantizer_output[i] += diff;
	}
    }
}
