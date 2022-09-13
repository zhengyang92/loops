#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;
typedef __int16_t int16_t;

int
fn (int AV1_NUM_REF_FRAMES, int i, int earliest_order_hint, int ref,
    int cur_frame_hint, int16_t shifted_order_hints[8], int8_t used_frame[8])
{
  for (i = 0; i < AV1_NUM_REF_FRAMES; i++)
    {
      int hint = shifted_order_hints[i];
      if (!used_frame[i] && hint >= cur_frame_hint
	  && (ref < 0 || hint < earliest_order_hint))
	{
	  ref = i;
	  earliest_order_hint = hint;
	}
    }
}
