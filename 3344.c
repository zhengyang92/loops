#include <stdint.h>
#include <stdio.h>






int
fn (float max_val, float *vec, float min_val, int len)
{
  for (int i = 0; i < len; i++)
    {
      if (!__builtin_isnormal (vec[i]) || fabsf (vec[i]) < 1e-8f)
	vec[i] = 0.f;
      else
	vec[i] = av_clipf_sse (vec[i], min_val, max_val);
    }
}
