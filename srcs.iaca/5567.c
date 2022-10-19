#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int hsub, uint8_t ** line, int plane, int *pixel_step,
    uint8_t * dst_color)
{
  for (plane = 0; plane < 4; plane++)
    {
      int line_size;
      int hsub1 = (plane == 1 || plane == 2) ? hsub : 0;
      pixel_step[plane] = 1;
      line_size = (w >> hsub1) * pixel_step[plane];
      line[plane] = av_malloc (line_size);
      memset (line[plane], dst_color[plane], line_size);
}}
