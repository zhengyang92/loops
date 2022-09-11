#include <stdint.h>
#include <stdio.h>






int
fn (int shift_start[4], unsigned int mask, int j, int shift_dec[4],
    unsigned int v, unsigned int out)
{
  for (j = shift_start[0]; j > -shift_dec[0]; j -= shift_dec[0])
    {
      if (j > 0)
	out |= v << j;
      else
	out |= (v >> (-j)) & mask;
    }
}
