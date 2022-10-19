#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *work, int work_len, int i)
{
  for (i = 2; i < work_len; i += 2)
    {
      float x = expf (work[i]);
      work[i] = x * cosf (work[i + 1]);
      work[i + 1] = x * sinf (work[i + 1]);
}}
