#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int y, int w, const unsigned int wide_filter_row_mask[2], int m_row_4,
    int ss_h, int h, int row_and_7, int t, int ss_v, int col_end, int m_row_8,
    int m_col, uint8_t (*mask)[8][4])
{
  for (y = row_and_7; y < h + row_and_7; y++)
     { IACA_START
      int col_mask_id = 2 - !(y & wide_filter_row_mask[ss_v]);
      mask[0][y][1] |= m_row_8;
      mask[0][y][2] |= m_row_4;
      if ((ss_h & ss_v) && (col_end & 1) && (y & 1))
	{
	  mask[1][y][col_mask_id] |= (t << (w - 1)) - t;
	}
      else
	{
	  mask[1][y][col_mask_id] |= m_col;
	}
      if (!ss_h)
	mask[0][y][3] |= m_col;
      if (!ss_v)
	{
	  if (ss_h && (col_end & 1))
	    mask[1][y][3] |= (t << (w - 1)) - t;
	  else
	    mask[1][y][3] |= m_col;
	}
     } IACA_END
}
