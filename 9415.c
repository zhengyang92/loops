#include <stdint.h>
#include <stdio.h>






int
fn (int out2[12], int *buf, int i, int *win)
{
  for (i = 0; i < 6; i++)
    {
      buf[4 * (i + 6 * 0)] =
	MULH ((1) * (out2[i]), win[i]) + buf[4 * (i + 6 * 0)];
      buf[4 * (i + 6 * 1)] = MULH ((1) * (out2[i + 6]), win[i + 6]);
      buf[4 * (i + 6 * 2)] = 0;
    }
}
