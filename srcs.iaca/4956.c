#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int tmpStride, int i, int srcStride, const int pad, int16_t * tmp,
    const uint16_t * src)
{
  const int h = 2;
  for (i = 0; i < h + 5; i++)
    {
      tmp[0] =
	(src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) +
	pad;
      tmp[1] =
	(src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) +
	pad;
      tmp += tmpStride;
      src += srcStride;
    }
}
