#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const uint32_t * prev_row, int kHistoBlueSubGreen,
    const uint32_t * curr_row, int kHistoRedSubGreen, uint32_t * histo,
    int width, int x, int kHistoGreenPred, int kHistoRedPred,
    int kHistoRedPredSubGreen, int kHistoGreen, int kHistoAlphaPred,
    int kHistoPalette, int kHistoRed, int kHistoAlpha, int kHistoBluePred,
    uint32_t pix_prev, int kHistoBluePredSubGreen, int kHistoBlue)
{
  for (x = 0; x < width; ++x)
     { IACA_START
      const uint32_t pix = curr_row[x];
      const uint32_t pix_diff = VP8LSubPixels (pix, pix_prev);
      pix_prev = pix;
      if ((pix_diff == 0) || (prev_row != ((void *) 0) && pix == prev_row[x]))
	{
	  continue;
	}
      AddSingle (pix, &histo[kHistoAlpha * 256], &histo[kHistoRed * 256],
		 &histo[kHistoGreen * 256], &histo[kHistoBlue * 256]);
      AddSingle (pix_diff, &histo[kHistoAlphaPred * 256],
		 &histo[kHistoRedPred * 256], &histo[kHistoGreenPred * 256],
		 &histo[kHistoBluePred * 256]);
      AddSingleSubGreen (pix, &histo[kHistoRedSubGreen * 256],
			 &histo[kHistoBlueSubGreen * 256]);
      AddSingleSubGreen (pix_diff, &histo[kHistoRedPredSubGreen * 256],
			 &histo[kHistoBluePredSubGreen * 256]);
      {
	const uint32_t hash = HashPix (pix);
	++histo[kHistoPalette * 256 + hash];
} IACA_END }}
