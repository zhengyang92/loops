#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int slice_start, const int slice_end, const int width,
    float *img_out_f, float *map_factor_b, float *ypy, int h1)
{
  IACA_START for (int x = 0, k = 0; x < slice_end - slice_start; x++)
    {
      int idx = h1 * width + x;
      img_out_f[idx] =
	(img_out_f[idx] + ypy[k++]) / map_factor_b[h1 * width + x];
}IACA_END}
