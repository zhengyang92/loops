#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int INTFLOAT;

int
fn (int j, INTFLOAT * z)
{
  for (j = 64; j < 128; j++)
     { IACA_START
      if (z[j] > 1 << 24)
	{
	  av_log (((void *) 0), 24,
		  "sbr_qmf_analysis: value %09d too large, setting to %09d\n",
		  z[j], 1 << 24);
	  z[j] = 1 << 24;
	}
      else if (z[j] < -(1 << 24))
	{
	  av_log (((void *) 0), 24,
		  "sbr_qmf_analysis: value %09d too small, setting to %09d\n",
		  z[j], -(1 << 24));
	  z[j] = -(1 << 24);
	}
} IACA_END }
