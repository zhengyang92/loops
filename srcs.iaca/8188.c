#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, float *ang, int frame_size, float *mag)
{
  for (j = 0; j < frame_size; j++)
     { IACA_START
      float a = ang[j];
      ang[j] -= mag[j];
      if (mag[j] > 0)
	ang[j] = -ang[j];
      if (ang[j] < 0)
	mag[j] = a;
     } IACA_END
}
