#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int8_t int8_t;

int
fn (int i, const int8_t * noise, const uint8_t * src, int len, uint8_t * dst)
{
  for (i = 0; i < len; i++)
    {
      int v = src[i] + noise[i];
      dst[i] = av_clip_uint8_c (v);
}}
