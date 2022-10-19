#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int largest, int qlevels[5])
{
  for (i = 0; i < 5; i++)
    {
      if (qlevels[i] < qlevels[largest])
	largest = i;
    }
}
