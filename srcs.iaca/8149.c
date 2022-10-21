#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float c, int i, const float *window, float b, float a, float *synth_buf,
    int j, float d)
{
  for (; j < 1024; j += 128)
     { IACA_START
      a += window[i + j] * (-synth_buf[31 - i + j - 1024]);
      b += window[i + j + 32] * (synth_buf[i + j - 1024]);
      c += window[i + j + 64] * (synth_buf[32 + i + j - 1024]);
      d += window[i + j + 96] * (synth_buf[63 - i + j - 1024]);
     } IACA_END
}
