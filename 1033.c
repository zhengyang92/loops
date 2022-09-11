#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t (*us)[4], int v_shift, int ui, int eh, int vi, int ew,
    int16_t (*vs)[4], int u_shift)
{
  int i = 0;
  for (int j = 0; j < 4; j++)
    {
      us[i][j] = u_shift + av_clip_c (ui + j - 1, 0, ew - 1);
      vs[i][j] = v_shift + av_clip_c (vi + i - 1, 0, eh - 1);
}}
