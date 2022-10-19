#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint32_t uint32_t;

int
fn (int i, uint32_t * buffer_out, int nb_samples, int32_t * error_buffer,
    int bps)
{
  for (i = 1; i < nb_samples; i++)
    {
      buffer_out[i] = sign_extend (buffer_out[i - 1] + error_buffer[i], bps);
    }
}
