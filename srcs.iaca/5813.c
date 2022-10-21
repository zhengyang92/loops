#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, int i, float min, float max, float *dst, int len)
{
  for (i = 0; i < len; i += 8)
     { IACA_START
      dst[i] = av_clipf_c (src[i], min, max);
      dst[i + 1] = av_clipf_c (src[i + 1], min, max);
      dst[i + 2] = av_clipf_c (src[i + 2], min, max);
      dst[i + 3] = av_clipf_c (src[i + 3], min, max);
      dst[i + 4] = av_clipf_c (src[i + 4], min, max);
      dst[i + 5] = av_clipf_c (src[i + 5], min, max);
      dst[i + 6] = av_clipf_c (src[i + 6], min, max);
      dst[i + 7] = av_clipf_c (src[i + 7], min, max);
     } IACA_END
}
