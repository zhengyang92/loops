#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int res, const int *data, int i)
{
  int b = 10;
  for (i = 0; i < 10; i++)
    {
      res = (((0x1000000 - data[i] * data[i]) >> 12) * res) >> 12;
      if (res == 0)
	return 0;
      while (res <= 0x3fff)
	{
	  b++;
	  res <<= 2;
	}
    }
}
