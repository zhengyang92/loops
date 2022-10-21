#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float cum_2pi, int work_len, float *pi_wraps, float prev_angle2,
    float prev_angle1, int i, float cum_1pi, float *work)
{
  for (i = 0; i <= work_len; i += 2)
     { IACA_START
      float angle = atan2f (work[i + 1], work[i]);
      float detect = 2 * 3.14159265358979323846;
      float delta = angle - prev_angle2;
      float adjust =
	detect * ((delta < -detect * .7f) - (delta > detect * .7f));
      prev_angle2 = angle;
      cum_2pi += adjust;
      angle += cum_2pi;
      detect = 3.14159265358979323846;
      delta = angle - prev_angle1;
      adjust = detect * ((delta < -detect * .7f) - (delta > detect * .7f));
      prev_angle1 = angle;
      cum_1pi += fabsf (adjust);
      pi_wraps[i >> 1] = cum_1pi;
      work[i] =
	safe_log (sqrtf
		  (((work[i]) * (work[i])) +
		   ((work[i + 1]) * (work[i + 1]))));
      work[i + 1] = 0;
} IACA_END }
