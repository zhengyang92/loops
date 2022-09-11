#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int64_t int64_t;

int
fn (int64_t cy, int i, uint8_t * y_table, int64_t yb)
{
  for (i = 0; i < 1024 - 110; i++)
    {
      y_table[i + 110] = av_clip_uint8_c ((yb + 0x8000) >> 16) >> 7;
      yb += cy;
    }
}
