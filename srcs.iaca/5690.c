#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int k, int m, float (*ap_delay)[3][37][2])
{
  for (m = 0; m < 3; m++)
    {
      memcpy (ap_delay[k][m], ap_delay[k][m] + 32,
	      5 * sizeof (ap_delay[k][m][0]));
    }
}
