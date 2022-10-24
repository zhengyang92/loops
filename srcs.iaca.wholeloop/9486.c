#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef __int16_t int16_t;

int
fn (size_t len, const int16_t * src, int i, int16_t * dst)
{
  IACA_START for (i = 0; i < len; i++)
    {
      int val = dst[i] + src[i];
      dst[i] = av_clip_int16_c (val);
}IACA_END}
