#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const double *hp, int buff_idx, int buffer_length, double *buffer2,
    const double *lp, int shift, int filter_length, double *buffer)
{
  double sum = 0.0;
  IACA_START for (int j = 0; j < (filter_length - shift + 1) / 2; j++)
    {
      const int idx = ((-j + buff_idx - 1) & ((buffer_length) - 1));
      sum +=
	buffer[idx] * lp[j * 2 + shift] + buffer2[idx] * hp[j * 2 + shift];
}IACA_END}
