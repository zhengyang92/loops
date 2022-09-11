#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __int16_t int16_t;

int
fn (int shift[4], int coeff[2][4], GetByteContext gb, int n, int16_t * s)
{
  for (n = 0; n < 4; n++, s += 32)
    {
      int level, pred;
      int byte = bytestream2_get_byteu (&gb);
      level = sign_extend (byte >> 4, 4) << shift[n];
      pred = s[-1] * coeff[0][n] + s[-2] * coeff[1][n];
      s[0] = av_clip_int16_c ((level + pred + 0x80) >> 8);
      level = sign_extend (byte, 4) << shift[n];
      pred = s[0] * coeff[0][n] + s[-1] * coeff[1][n];
      s[1] = av_clip_int16_c ((level + pred + 0x80) >> 8);
}}
