#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef VP8LMultipliers;

int
fn (VP8LMultipliers prev_x, const int *accumulated_blue_histo,
    VP8LMultipliers prev_y, int iter, const int delta, int tile_width,
    int tile_height, const int8_t offset[8][2], int quality,
    const uint32_t * argb, int axis, float best_diff, int stride)
{
  int red_to_blue_best = 0;
  int green_to_blue_best = 0;
  for (axis = 0; axis < 8; ++axis)
     { IACA_START
      const int green_to_blue_cur =
	offset[axis][0] * delta + green_to_blue_best;
      const int red_to_blue_cur = offset[axis][1] * delta + red_to_blue_best;
      const float cur_diff =
	GetPredictionCostCrossColorBlue (argb, stride, tile_width,
					 tile_height, prev_x, prev_y,
					 green_to_blue_cur, red_to_blue_cur,
					 accumulated_blue_histo);
      if (cur_diff < best_diff)
	{
	  best_diff = cur_diff;
	  green_to_blue_best = green_to_blue_cur;
	  red_to_blue_best = red_to_blue_cur;
	}
      if (quality < 25 && iter == 4)
	{
	  break;
	}
     } IACA_END
}
