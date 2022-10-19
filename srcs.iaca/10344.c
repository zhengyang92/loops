#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int pad, int width, int c_im, int w, int width_col, int c, int h_offset,
    int w_offset, int stride, int channels, int height, float *data_col,
    int height_col, int h, float *data_im)
{
  for (w = 0; w < width_col; ++w)
    {
      int im_row = h_offset + h * stride;
      int im_col = w_offset + w * stride;
      int col_index = (c * height_col + h) * width_col + w;
      double val = data_col[col_index];
      col2im_add_pixel (data_im, height, width, channels, im_row, im_col,
			c_im, pad, val);
}}
