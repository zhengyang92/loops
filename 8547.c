#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, uint8_t * udst, const int mid, int x, const int factor,
    uint8_t * ydst, uint8_t * vdst)
{
  for (x = 0; x < w; x++)
    {
      int c = factor * x / w;
      ydst[x] = mid;
      udst[x] = mid;
      vdst[x] = c;
}}
