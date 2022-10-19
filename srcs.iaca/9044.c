#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int64_t pos, int i, int ret, int64_t best_pos, int best_valid,
    int64_t out_pos[4])
{
  for (i = 0; i < ret; i++)
    {
      if (llabs (best_pos - pos) > llabs (out_pos[i] - pos))
	{
	  best_pos = out_pos[i];
	  best_valid = ret;
	}
    }
}
