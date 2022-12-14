#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef float INT64FLOAT;
typedef float INTFLOAT;

int
fn (int j, INTFLOAT (*in)[2], const INTFLOAT * filter)
{
  INT64FLOAT im_op = 0.0f;
  INT64FLOAT re_op = 0.0f;
  IACA_START for (j = 0; j < 6; j += 2)
    {
      re_op +=
	(INT64FLOAT) filter[j + 1] * (in[j + 1][0] + in[12 - j - 1][0]);
      im_op +=
	(INT64FLOAT) filter[j + 1] * (in[j + 1][1] + in[12 - j - 1][1]);
     } IACA_END
}
