#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t stride, uint8_t * dst, int i, int temp[16])
{
  for (i = 0; i < 4; i++)
    {
      const int z0 = 13 * (temp[4 * 0 + i] + temp[4 * 2 + i]) + 0x200;
      const int z1 = 13 * (temp[4 * 0 + i] - temp[4 * 2 + i]) + 0x200;
      const int z2 = 7 * temp[4 * 1 + i] - 17 * temp[4 * 3 + i];
      const int z3 = 17 * temp[4 * 1 + i] + 7 * temp[4 * 3 + i];
      dst[0] = av_clip_uint8_c (dst[0] + ((z0 + z3) >> 10));
      dst[1] = av_clip_uint8_c (dst[1] + ((z1 + z2) >> 10));
      dst[2] = av_clip_uint8_c (dst[2] + ((z1 - z2) >> 10));
      dst[3] = av_clip_uint8_c (dst[3] + ((z0 - z3) >> 10));
      dst += stride;
}}
