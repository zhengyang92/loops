#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * data, int i, int msr)
{
  IACA_START for (i = 0; i < 160; i++)
    {
      msr = av_clip_int16_c (data[i] + gsm_mult (msr, 28180));
      data[i] = av_clip_int16_c (msr << 1) & ~7;
     } IACA_END
}
