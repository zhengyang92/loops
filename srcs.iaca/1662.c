#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float diff_isf[14])
{
  for (i = 1; i < 20 - 16; i++)
    if (diff_isf[i] + diff_isf[i - 1] < 5.0)
      {
	if (diff_isf[i] > diff_isf[i - 1])
	  {
	    diff_isf[i - 1] = 5.0 - diff_isf[i];
	  }
	else
	  diff_isf[i] = 5.0 - diff_isf[i - 1];
      }
}
