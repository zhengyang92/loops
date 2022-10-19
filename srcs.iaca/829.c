#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int top, const int height, uint8_t * ptr, const int right,
    const int bottom, const int linesize, const int width, const int left)
{
  for (int y = top; y < height - bottom; y++)
    {
      memset (ptr + linesize * y, ptr[linesize * y + left], left);
      memset (ptr + linesize * y + width - right,
	      (ptr + linesize * y + width - right)[-1], right);
}}
