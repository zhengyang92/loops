#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (int32_t gy, int32_t by, int i, const int chromWidth, uint8_t * ydst,
    const uint8_t * src, int32_t ry)
{
  for (i = 0; i < chromWidth; i++)
    {
      unsigned int b = src[6 * i + 0];
      unsigned int g = src[6 * i + 1];
      unsigned int r = src[6 * i + 2];
      unsigned int Y = ((ry * r + gy * g + by * b) >> 15) + 16;
      ydst[2 * i] = Y;
      b = src[6 * i + 3];
      g = src[6 * i + 4];
      r = src[6 * i + 5];
      Y = ((ry * r + gy * g + by * b) >> 15) + 16;
      ydst[2 * i + 1] = Y;
}}
