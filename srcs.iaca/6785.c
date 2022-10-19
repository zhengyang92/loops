#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int8_t (*coding_method)[30][64], int ch, int sb)
{
  for (j = 0; j < 64; j++)
    if (sb >= 10)
      {
	if (coding_method[ch][sb][j] < 10)
	  coding_method[ch][sb][j] = 10;
      }
    else
      {
	if (sb >= 2)
	  {
	    if (coding_method[ch][sb][j] < 16)
	      coding_method[ch][sb][j] = 16;
	  }
	else
	  {
	    if (coding_method[ch][sb][j] < 30)
	      coding_method[ch][sb][j] = 30;
	  }
      }
}
