#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (float total, const int w, const uint16_t * src)
{
  for (int x = 0; x < w; x++)
    {
      total += src[x];
}}
