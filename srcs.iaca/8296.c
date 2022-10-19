#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int fill, ptrdiff_t bytewidth, const ptrdiff_t *dst_linesize, int height,
    uint8_t * data)
{
  for (; height > 0; height--)
    {
      memset (data, fill, bytewidth);
      data += dst_linesize[0];
    }
}
