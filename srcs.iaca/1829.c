#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (const int32_t * in, int i, int shift_bits, int32_t input_buffer[20],
    int len, int32_t input_buffer2[20])
{
  for (i = 0; i < len + 4; i++)
     { IACA_START
      input_buffer[i] = norm__ (in[i], 7);
      input_buffer2[i] = norm__ (in[i], shift_bits);
     } IACA_END
}
