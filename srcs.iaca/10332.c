#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int dataOff, float *CDU)
{
  for (dataOff = 0; dataOff < 64; dataOff += 8)
    {
      stbiw__jpg_DCT (&CDU[dataOff], &CDU[dataOff + 1], &CDU[dataOff + 2],
		      &CDU[dataOff + 3], &CDU[dataOff + 4], &CDU[dataOff + 5],
		      &CDU[dataOff + 6], &CDU[dataOff + 7]);
    }
}
