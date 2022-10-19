#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int num_data, uint8_t * p, int j, int data_len[256])
{
  int xd_size = 1;
  int offset = 1;
  for (j = 0; j < num_data - 1; j++)
    {
      unsigned delta = av_xiphlacing (&p[offset], data_len[j]);
      do
	{
	  if (!(delta <= xd_size - offset))
	    {
	      av_log (((void *) 0), 0, "Assertion %s failed at %s:%d\n",
		      "delta <= xd_size - offset", "program.c", 412);
	      abort ();
	    }
	}
      while (0);
      offset += delta;
    }
}
