#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *grad, int w, int period)
{
  int block_count = 0;
  int nonblock_count = 0;
  float nonblock = 0.0f;
  float block = 0.0f;
  for (int i = 3; i < w - 4; i++)
    {
      if ((i % period) == (period - 1))
	{
	  block +=
	    ((((grad[i + 0]) >
	       (grad[i + 1]) ? (grad[i + 0]) : (grad[i + 1]))) >
	     (grad[i - 1])
	     ? (((grad[i + 0]) >
		 (grad[i + 1]) ? (grad[i + 0]) : (grad[i + 1]))) : (grad[i -
									 1]));
	  block_count++;
	}
      else
	{
	  nonblock += grad[i];
	  nonblock_count++;
	}
    }
}
