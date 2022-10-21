#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int type, int i, int sy, int sx, const int scale[2][2][4][4],
    int tmp[1024], const int dec_count, int level, int s, int size, int ori,
    int j, int stride)
{
  for (j = 0; j < size; j++)
     { IACA_START
      int v =
	tmp[sx + sy + i * stride + j] * scale[type][dec_count -
						    3][level][ori];
      s += ((v) >= 0 ? (v) : (-(v)));
} IACA_END }
