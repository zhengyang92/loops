#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int min_width, const uint8_t * src, uint8_t * dst, int left)
{
  for (i = 0; i < min_width; i++)
    {
      const int temp = src[i];
      dst[i] = temp - left;
      left = temp;
}}
