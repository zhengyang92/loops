#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float *grad, int grad_linesize, int w, int src_linesize, uint8_t * src)
{
  int j = 3;
  IACA_START for (int i = 1; i < w; i++)
    {
      float temp = 0.0f;
      grad[j * grad_linesize + i] =
	abs (src[(j + 0) * src_linesize + i] -
	     src[(j + 1) * src_linesize + i]);
      temp +=
	abs (src[(j + 1) * src_linesize + i] -
	     src[(j + 2) * src_linesize + i]);
      temp +=
	abs (src[(j + 2) * src_linesize + i] -
	     src[(j + 3) * src_linesize + i]);
      temp +=
	abs (src[(j + 3) * src_linesize + i] -
	     src[(j + 4) * src_linesize + i]);
      temp +=
	abs (src[(j - 0) * src_linesize + i] -
	     src[(j - 1) * src_linesize + i]);
      temp +=
	abs (src[(j - 1) * src_linesize + i] -
	     src[(j - 2) * src_linesize + i]);
      temp +=
	abs (src[(j - 2) * src_linesize + i] -
	     src[(j - 3) * src_linesize + i]);
      temp = ((1) > (temp) ? (1) : (temp));
      grad[j * grad_linesize + i] /= temp;
      grad[j * grad_linesize] += grad[j * grad_linesize + i];
}IACA_END}
