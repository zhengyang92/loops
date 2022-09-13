#include <stdint.h>
#include <stdio.h>






int
fn (int type, int i, int sy, int sx, const int dec_count,
    const int scale[2][2][4][4], int level, int tmp[1024], int j, int size,
    int ori, int s, int stride)
{
  for (j = 0; j < size; j++)
    {
      int v =
	tmp[sx + sy + i * stride + j] * scale[type][dec_count -
						    3][level][ori];
      s += ((v) >= 0 ? (v) : (-(v)));
}}
