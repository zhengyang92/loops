#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int dataOff, float *CDU)
{
  for (dataOff = 0; dataOff < 8; ++dataOff)
    {
      stbiw__jpg_DCT (&CDU[dataOff], &CDU[dataOff + 8], &CDU[dataOff + 16],
		      &CDU[dataOff + 24], &CDU[dataOff + 32],
		      &CDU[dataOff + 40], &CDU[dataOff + 48],
		      &CDU[dataOff + 56]);
    }
}
