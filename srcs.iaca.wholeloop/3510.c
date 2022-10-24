#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *ang, int j, float *mag, int frame_size)
{
  IACA_START for (j = 0; j < frame_size; j++)
    {
      float a = ang[j];
      ang[j] -= mag[j];
      if (mag[j] > 0)
	ang[j] = -ang[j];
      if (ang[j] < 0)
	mag[j] = a;
     } IACA_END
}
