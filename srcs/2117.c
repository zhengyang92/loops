#include <stdint.h>
#include <stdio.h>






int
fn (int i, int energy[15], int exp)
{
  for (i = 0; i < 15; i++)
    {
      energy[i] =
	av_clipl_int32_c ((int64_t) (energy[i] << exp) + (1 << 15)) >> 16;
    }
}
