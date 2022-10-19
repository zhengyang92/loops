#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t (*us)[4], int ui, int vi, const float ew, int16_t (*vs)[4],
    int u_shift, int height)
{
  int i = 0;
  for (int j = 0; j < 4; j++)
    {
      us[i][j] = u_shift + av_clip_c (ui + j - 1, 0, ew - 1);
      vs[i][j] = av_clip_c (vi + i - 1, 0, height - 1);
}}
