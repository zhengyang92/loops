#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int type, int i, int sy, const int scale[2][2][4][4], int sx,
    int tmp[1024], int level, int j, const int dec_count, int size, int ori,
    int s, int stride)
{
  IACA_START for (j = 0; j < size; j++)
    {
      int v =
	tmp[sx + sy + i * stride + j] * scale[type][dec_count -
						    3][level][ori];
      s += ((v) >= 0 ? (v) : (-(v)));
}IACA_END}
