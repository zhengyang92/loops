#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int8_t (*tone_level_idx_temp)[30][64], int esp_40,
    int8_t (*coding_method)[30][64], int comp, int ch, int tmp, int j, int sb)
{
  IACA_START for (j = 0; j < 64; j++)
    {
      comp = tone_level_idx_temp[ch][sb][j] * esp_40 * 10;
      if (comp < 0)
	comp += 0xff;
      comp /= 256;
      switch (sb)
	{
	case 0:
	  if (comp < 30)
	    comp = 30;
	  comp += 15;
	  break;
	case 1:
	  if (comp < 24)
	    comp = 24;
	  comp += 10;
	  break;
	case 2:
	case 3:
	case 4:
	  if (comp < 16)
	    comp = 16;
	}
      if (comp <= 5)
	tmp = 0;
      else if (comp <= 10)
	tmp = 10;
      else if (comp <= 16)
	tmp = 16;
      else if (comp <= 24)
	tmp = -1;
      else
	tmp = 0;
      coding_method[ch][sb][j] = ((tmp & 0xfffa) + 30) & 0xff;
     } IACA_END
}
