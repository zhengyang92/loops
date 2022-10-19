#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int x_end, int y, const uint32_t * cur_srcp, const int prv_src_linesize,
    int y_end, const int cur_src_linesize, const uint32_t * prv_srcp)
{
  int y_start = 0;
  int same_column = 1;
  for (y = y_start; y <= y_end; y++)
    {
      if (prv_srcp[y * prv_src_linesize + x_end] !=
	  cur_srcp[y * cur_src_linesize + x_end])
	{
	  same_column = 0;
	  break;
	}
    }
}
