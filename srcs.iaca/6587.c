#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float is_table[2][16], int i)
{
  for (i = 0; i < 7; i++)
    {
      float f;
      float v;
      if (i != 6)
	{
	  f = tan ((double) i * 3.14159265358979323846 / 12.0);
	  v = ((float) (f / (1.0 + f)));
	}
      else
	{
	  v = ((float) (1.0));
	} is_table[0][i] = v;
      is_table[1][6 - i] = v;
}}
