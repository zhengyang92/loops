#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float highest, float workT[32])
{
  int found_indx = 0;
  for (i = 0; i < 32; i++)
    {
      if (workT[i] > highest)
	{
	  highest = workT[i];
	  found_indx = i;
	}
    }
}
