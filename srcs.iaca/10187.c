#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef unsigned char U8;

int
fn (const I32 iWidth, U8 * piDstPixel, const float *pfltSrcPixel, I32 x)
{
  for (x = 0; x < iWidth; x++)
    {
      const float fltRed =
	((pfltSrcPixel[3 * x]) > (0.0F) ? (pfltSrcPixel[3 * x]) : (0.0F));
      const float fltGreen =
	((pfltSrcPixel[3 * x + 1]) >
	 (0.0F) ? (pfltSrcPixel[3 * x + 1]) : (0.0F));
      const float fltBlue =
	((pfltSrcPixel[3 * x + 2]) >
	 (0.0F) ? (pfltSrcPixel[3 * x + 2]) : (0.0F));
      float fltMaxPos = fltRed;
      if (fltGreen > fltMaxPos)
	fltMaxPos = fltGreen;
      if (fltBlue > fltMaxPos)
	fltMaxPos = fltBlue;
      if (fltMaxPos < 1e-32)
	{
	  piDstPixel[4 * x] = 0;
	  piDstPixel[4 * x + 1] = 0;
	  piDstPixel[4 * x + 2] = 0;
	  piDstPixel[4 * x + 3] = 0;
	}
      else
	{
	  int e;
	  const float fltScale =
	    (float) frexp (fltMaxPos, &e) * 256 / fltMaxPos;
	  piDstPixel[4 * x] = (U8) (fltRed * fltScale);
	  piDstPixel[4 * x + 1] = (U8) (fltGreen * fltScale);
	  piDstPixel[4 * x + 2] = (U8) (fltBlue * fltScale);
	  piDstPixel[4 * x + 3] = (U8) (e + 128);
}}}
