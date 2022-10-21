#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t (*us)[4], const int vi, int width, int16_t (*vs)[4],
    const int visible, const int ui, int height)
{
  int i = 0;
  for (int j = 0; j < 4; j++)
     { IACA_START
      us[i][j] = visible ? av_clip_c (ui + j - 1, 0, width - 1) : 0;
      vs[i][j] = visible ? av_clip_c (vi + i - 1, 0, height - 1) : 0;
} IACA_END }
