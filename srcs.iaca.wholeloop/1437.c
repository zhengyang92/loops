#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int *current, int tags, int i, uint8_t (*layout_map)[3], int TYPE_CPE,
    int pos, int AAC_CHANNEL_FRONT)
{
  int num_pos_channels = 0;
  int first_cpe = 0;
  int sce_parity = 0;
  IACA_START for (i = *current; i < tags; i++)
    {
      if (layout_map[i][2] != pos)
	break;
      if (layout_map[i][0] == TYPE_CPE)
	{
	  if (sce_parity)
	    {
	      if (pos == AAC_CHANNEL_FRONT && !first_cpe)
		{
		  sce_parity = 0;
		}
	      else
		{
		  return -1;
		}
	    }
	  num_pos_channels += 2;
	  first_cpe = 1;
	}
      else
	{
	  num_pos_channels++;
	  sce_parity ^= 1;
	}
     } IACA_END
}
