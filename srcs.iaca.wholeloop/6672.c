#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, int D, int *block, int t3, int t2, ptrdiff_t stride,
    int block_size, const int hsize, int B, int C, uint8_t * dst, int t1,
    int t4, int A)
{
  IACA_START for (i = 0; i < hsize; i++)
    {
      A = block[i];
      B = block[i + hsize];
      C = block[i + hsize * block_size];
      D = block[i + hsize * block_size + hsize];
      t1 = A - B;
      t2 = C - D;
      t3 = A + B;
      t4 = C + D;
      dst[i * 2] = av_clip_uint8_c (t1 - t2);
      dst[i * 2 + stride] = av_clip_uint8_c (t1 + t2);
      dst[i * 2 + 1] = av_clip_uint8_c (t3 - t4);
      dst[i * 2 + 1 + stride] = av_clip_uint8_c (t3 + t4);
     } IACA_END
}
