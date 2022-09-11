#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * srcp, int x, const int cthresh6, const int width,
    uint8_t * cmkp, const int cthresh, const int src_linesize)
{
  for (x = 0; x < width; x++)
    {
      const int s1 = abs (srcp[x] - srcp[x - src_linesize]);
      const int s2 = abs (srcp[x] - srcp[x + src_linesize]);
      if (s1 > cthresh && s2 > cthresh
	  && abs (4 * srcp[x] -
		  3 * (srcp[x + (-1) * src_linesize] +
		       srcp[x + (1) * src_linesize]) + (srcp[x +
							     (-2) *
							     src_linesize] +
							srcp[x +
							     (-2) *
							     src_linesize])) >
	  cthresh6)
	cmkp[x] = 0xff;
    }
}
