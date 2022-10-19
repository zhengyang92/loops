#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned int U32;
typedef struct CAdaptiveScan
{
  U32 uTotal;
  U32 uScan;
} CAdaptiveScan;
typedef int PixelI;
typedef int Int;

int
fn (unsigned int iThOff, Int k, const Int iModelBits, CAdaptiveScan * pScan,
    unsigned int iTh, Int iRun, const PixelI * pCoeffs, Int iTemp,
    Int * pRLCoeffs, const Int iCount, Int iLevel)
{
  Int iNumNonzero = 1;
  for (k = 2; k < iCount; k++)
    {
      iRun++;
      iLevel = pCoeffs[pScan[k].uScan];
      if ((unsigned int) (iLevel + iThOff) >= iTh)
	{
	  iTemp = abs (iLevel) >> iModelBits;
	  pScan[k].uTotal++;
	  if (pScan[k].uTotal > pScan[k - 1].uTotal)
	    {
	      CAdaptiveScan cTemp = pScan[k];
	      pScan[k] = pScan[k - 1];
	      pScan[k - 1] = cTemp;
	    }
	  pRLCoeffs[iNumNonzero * 2] = iRun - 1;
	  pRLCoeffs[iNumNonzero * 2 + 1] = (iLevel < 0) ? -iTemp : iTemp;
	  iNumNonzero++;
	  iRun = 0;
	}
    }
}
