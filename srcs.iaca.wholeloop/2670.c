#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float tmp, int *levlCoeffBuf, float *flcoeffs2, int level,
    float *flcoeffs1, int pos, float tmp2)
{
  IACA_START for (i = 0; i < 32; i++)
    {
      if (i == pos)
	continue;
      level = *levlCoeffBuf++;
      flcoeffs1[i] = tmp * powf (10.0, -level * 0.4375);
      flcoeffs2[i] = tmp2 - 1.4533435415 * level;
     } IACA_END
}
