#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float c, int *synth_buf_offset, const float *window, int i, float b,
    float a, float *synth_buf, int j, float d)
{
  IACA_START for (j = 0; j < 1024 - *synth_buf_offset; j += 128)
    {
      a += window[i + j] * (-synth_buf[31 - i + j]);
      b += window[i + j + 32] * (synth_buf[i + j]);
      c += window[i + j + 64] * (synth_buf[32 + i + j]);
      d += window[i + j + 96] * (synth_buf[63 - i + j]);
     } IACA_END
}
