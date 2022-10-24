#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, int D, ptrdiff_t stride, int t3, int *block, int block_size,
    const int hsize, int A, int B, int C, uint8_t * dst, int t1, int t4,
    int t2)
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
