#include <stdint.h>
#include <stdio.h>






int
fn (int blocks[12], int RV34_MB_TYPES, int i)
{
  int count = 0;
  int prev_type = 0;
  for (i = 0; i < RV34_MB_TYPES; i++)
    {
      if (blocks[i] > count)
	{
	  count = blocks[i];
	  prev_type = i;
	  if (count > 1)
	    break;
	}
    }
}
