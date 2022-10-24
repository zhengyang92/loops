#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float postscale, float min, float max, int length, float *buffer)
{
  IACA_START for (int i = 0; i < length; i++)
    {
      buffer[i] *= postscale;
      buffer[i] = av_clipf_sse (buffer[i], min, max);
}IACA_END}
