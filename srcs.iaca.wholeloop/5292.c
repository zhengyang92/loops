#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *vec, float max_val, int len, float min_val)
{
  IACA_START for (int i = 0; i < len; i++)
    {
      if (!__builtin_isnormal (vec[i]) || fabsf (vec[i]) < 1e-8f)
	vec[i] = 0.f;
      else
	vec[i] = av_clipf_sse (vec[i], min_val, max_val);
     } IACA_END
}
