#include <stdint.h>
#include <stdio.h>






int
fn (int attacks[9], int i)
{
  int grouping = 0;
  for (i = 0; i < 9; i++)
    {
      if (attacks[i])
	{
	  grouping = i;
	  break;
	}
    }
}
