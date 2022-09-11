#include <stdint.h>
#include <stdio.h>






int
fn (float *buf, float *out_ptr, int i)
{
  for (i = 0; i < 6; i++)
    {
      *out_ptr = buf[4 * i];
      out_ptr += 32;
    }
}
