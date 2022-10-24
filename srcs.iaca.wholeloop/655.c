#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float *grad, int w, int grad_linesize, int src_linesize, uint8_t * src)
{
  int j = 1;
  IACA_START for (int i = 3; i < w - 4; i++)
    {
      float temp = 0.0f;
      grad[j * grad_linesize + i] =
	abs (src[j * src_linesize + i + 0] - src[j * src_linesize + i + 1]);
      temp +=
	abs (src[j * src_linesize + i + 1] - src[j * src_linesize + i + 2]);
      temp +=
	abs (src[j * src_linesize + i + 2] - src[j * src_linesize + i + 3]);
      temp +=
	abs (src[j * src_linesize + i + 3] - src[j * src_linesize + i + 4]);
      temp +=
	abs (src[j * src_linesize + i - 0] - src[j * src_linesize + i - 1]);
      temp +=
	abs (src[j * src_linesize + i - 1] - src[j * src_linesize + i - 2]);
      temp +=
	abs (src[j * src_linesize + i - 2] - src[j * src_linesize + i - 3]);
      temp = ((1) > (temp) ? (1) : (temp));
      grad[j * grad_linesize + i] /= temp;
      grad[i] += grad[j * grad_linesize + i];
}IACA_END}
