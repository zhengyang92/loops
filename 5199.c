#include <stdint.h>
#include <stdio.h>






int
fn (int add4, int8_t (*tone_level_idx_temp)[30][64], int ch, int add3, int j,
    int tmp, int8_t (*tone_level_idx)[30][64],
    const int8_t tone_level_idx_offset_table[30][4], int add1, int sb,
    int add2)
{
  for (j = 1; j < 63; j++)
    {
      add1 = tone_level_idx[ch][sb][j] - 10;
      if (add1 < 0)
	add1 = 0;
      add2 = add3 = add4 = 0;
      if (sb > 1)
	{
	  add2 =
	    tone_level_idx[ch][sb - 2][j] +
	    tone_level_idx_offset_table[sb][0] - 6;
	  if (add2 < 0)
	    add2 = 0;
	}
      if (sb > 0)
	{
	  add3 =
	    tone_level_idx[ch][sb - 1][j] +
	    tone_level_idx_offset_table[sb][1] - 6;
	  if (add3 < 0)
	    add3 = 0;
	}
      if (sb < 29)
	{
	  add4 =
	    tone_level_idx[ch][sb + 1][j] +
	    tone_level_idx_offset_table[sb][3] - 6;
	  if (add4 < 0)
	    add4 = 0;
	}
      tmp = tone_level_idx[ch][sb][j + 1] * 2 - add4 - add3 - add2 - add1;
      if (tmp < 0)
	tmp = 0;
      tone_level_idx_temp[ch][sb][j + 1] = tmp & 0xff;
    }
}
