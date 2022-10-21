#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct PsyLamePreset
{
  int quality;
  float st_lrm;
} PsyLamePreset;

int
fn (const PsyLamePreset psy_abr_map[13], int i, int upper_range_kbps,
    int bitrate, int lower_range, int lower_range_kbps)
{
  int upper_range = 12;
  for (i = 1; i < 13; i++)
     { IACA_START
      if (((bitrate) >
	   (psy_abr_map[i].quality) ? (bitrate) : (psy_abr_map[i].quality)) !=
	  bitrate)
	{
	  upper_range = i;
	  upper_range_kbps = psy_abr_map[i].quality;
	  lower_range = i - 1;
	  lower_range_kbps = psy_abr_map[i - 1].quality;
	  break;
	}
     } IACA_END
}
