#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float qmf_48tap_half[24], float qmf_window[48])
{
  for (int i = 0; i < 24; i++)
     { IACA_START
      float s = qmf_48tap_half[i] * 2.0;
      qmf_window[i] = qmf_window[47 - i] = s;
} IACA_END }
