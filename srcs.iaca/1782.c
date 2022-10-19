#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;
typedef __int16_t int16_t;

int
fn (int AV1_NUM_REF_FRAMES, int ref, int cur_frame_hint,
    int16_t shifted_order_hints[8], int8_t used_frame[8],
    int latest_order_hint, int j)
{
  for (j = 0; j < AV1_NUM_REF_FRAMES; j++)
    {
      int hint = shifted_order_hints[j];
      if (!used_frame[j] && hint < cur_frame_hint
	  && (ref < 0 || hint >= latest_order_hint))
	{
	  ref = j;
	  latest_order_hint = hint;
	}
    }
}
