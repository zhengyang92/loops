#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int64_t int64_t;

int
fn (int *synth_buf_offset, int i, const int32_t * window, int64_t d,
    int64_t a, int64_t b, int64_t c, int j, int32_t * synth_buf)
{
  for (j = 0; j < 512 - *synth_buf_offset; j += 64)
     { IACA_START
      a += (int64_t) window[i + j] * synth_buf[i + j];
      b += (int64_t) window[i + j + 16] * synth_buf[15 - i + j];
      c += (int64_t) window[i + j + 32] * synth_buf[16 + i + j];
      d += (int64_t) window[i + j + 48] * synth_buf[31 - i + j];
     } IACA_END
}
