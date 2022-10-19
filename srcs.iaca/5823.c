#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, double s[64], int i)
{
  for (i = 0; i < 8; i++)
    {
      if (j && j != 4)
	if (i && i != 4)
	  s[j * 8 + i] =
	    cos (j * 3.14159265358979323846 / 16.0) * cos (i *
							   3.14159265358979323846
							   / 16.0) * 2.0;
	else
	  s[j * 8 + i] = cos (j * 3.14159265358979323846 / 16.0) * sqrt (2.0);
      else if (i && i != 4)
	s[j * 8 + i] = cos (i * 3.14159265358979323846 / 16.0) * sqrt (2.0);
      else
	s[j * 8 + i] = 1.0;
    }
}
