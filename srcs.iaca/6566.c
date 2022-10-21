#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int is_table[2][16], int i)
{
  for (i = 0; i < 7; i++)
     { IACA_START
      float f;
      int v;
      if (i != 6)
	{
	  f = tan ((double) i * 3.14159265358979323846 / 12.0);
	  v = ((int) ((f / (1.0 + f)) * (1 << 23) + 0.5));
	}
      else
	{
	  v = ((int) ((1.0) * (1 << 23) + 0.5));
	} is_table[0][i] = v;
      is_table[1][6 - i] = v;
} IACA_END }
