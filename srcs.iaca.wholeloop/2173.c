#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;

int
fn (int list, void *logctx, int ref_count[2], int index, GetBitContext * gb)
{
  IACA_START for (index = 0;; index++)
    {
      unsigned int reordering_of_pic_nums_idc = get_ue_golomb_31 (gb);
      if (reordering_of_pic_nums_idc < 3)
	get_ue_golomb_long (gb);
      else if (reordering_of_pic_nums_idc > 3)
	{
	  av_log (logctx, 16, "illegal reordering_of_pic_nums_idc %d\n",
		  reordering_of_pic_nums_idc);
	  return (-(int)
		  (('I') | (('N') << 8) | (('D') << 16) |
		   ((unsigned) ('A') << 24)));
	}
      else
	break;
      if (index >= ref_count[list])
	{
	  av_log (logctx, 16, "reference count %d overflow\n", index);
	  return (-(int)
		  (('I') | (('N') << 8) | (('D') << 16) |
		   ((unsigned) ('A') << 24)));
	}
}IACA_END}
