#include <stdint.h>
#include <stdio.h>






int
fn (float out2[12], float *win, float *buf, int i)
{
  for (i = 0; i < 6; i++)
    {
      buf[4 * (i + 6 * 0)] =
	((1) * (win[i]) * (out2[i])) + buf[4 * (i + 6 * 0)];
      buf[4 * (i + 6 * 1)] = ((1) * (win[i + 6]) * (out2[i + 6]));
      buf[4 * (i + 6 * 2)] = 0;
    }
}
