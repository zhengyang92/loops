#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float out2[12], float *win, int i, float *buf)
{
  for (i = 0; i < 6; i++)
     { IACA_START
      buf[4 * (i + 6 * 0)] =
	((1) * (win[i]) * (out2[i])) + buf[4 * (i + 6 * 0)];
      buf[4 * (i + 6 * 1)] = ((1) * (win[i + 6]) * (out2[i + 6]));
      buf[4 * (i + 6 * 2)] = 0;
     } IACA_END
}
