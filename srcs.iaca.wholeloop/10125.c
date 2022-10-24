#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned int U32;
typedef struct CAdaptiveScan
{
  U32 uTotal;
  U32 uScan;
} CAdaptiveScan;
typedef int Int;
typedef int PixelI;

int
fn (Int k, PixelI * pCoeffs, CAdaptiveScan * pScan, Int aRLCoeffs[32],
    Int iNumNonzero)
{
  Int iIndex = 0;
  IACA_START for (k = 0; k < iNumNonzero; k++)
    {
      iIndex += aRLCoeffs[k * 2];
      pCoeffs[pScan[iIndex].uScan] = aRLCoeffs[k * 2 + 1];
      pScan[iIndex].uTotal++;
      if (pScan[iIndex].uTotal > pScan[iIndex - 1].uTotal)
	{
	  CAdaptiveScan cTemp = pScan[iIndex];
	  pScan[iIndex] = pScan[iIndex - 1];
	  pScan[iIndex - 1] = cTemp;
	}
      iIndex++;
     } IACA_END
}
