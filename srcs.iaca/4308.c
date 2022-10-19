#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *grad, int grad_linesize, int h, int period)
{
  int block_count = 0;
  int nonblock_count = 0;
  float nonblock = 0.0f;
  float block = 0.0f;
  for (int j = 3; j < h - 4; j++)
    {
      if ((j % period) == (period - 1))
	{
	  block +=
	    ((((grad[(j + 0) * grad_linesize]) >
	       (grad[(j + 1) * grad_linesize])
	       ? (grad[(j + 0) * grad_linesize])
	       : (grad[(j + 1) * grad_linesize]))) >
	     (grad[(j - 1) * grad_linesize])
	     ? (((grad[(j + 0) * grad_linesize]) >
		 (grad[(j + 1) * grad_linesize])
		 ? (grad[(j + 0) * grad_linesize])
		 : (grad[(j + 1) * grad_linesize]))) : (grad[(j -
							      1) *
							     grad_linesize]));
	  block_count++;
	}
      else
	{
	  nonblock += grad[j * grad_linesize];
	  nonblock_count++;
	}
    }
}
