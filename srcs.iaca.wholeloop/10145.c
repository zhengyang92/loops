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
fn (Int k, CAdaptiveScan * pScan, Int iRun, const PixelI * pCoeffs,
    Int * pRLCoeffs, const Int iCount, Int iLevel)
{
  Int iNumNonzero = 1;
  IACA_START for (k = 2; k < iCount; k++)
    {
      iLevel = pCoeffs[pScan[k].uScan];
      iRun++;
      if (iLevel)
	{
	  pScan[k].uTotal++;
	  if (pScan[k].uTotal > pScan[k - 1].uTotal)
	    {
	      CAdaptiveScan cTemp = pScan[k];
	      pScan[k] = pScan[k - 1];
	      pScan[k - 1] = cTemp;
	    }
	  pRLCoeffs[iNumNonzero * 2] = iRun - 1;
	  pRLCoeffs[iNumNonzero * 2 + 1] = iLevel;
	  iNumNonzero++;
	  iRun = 0;
	}
     } IACA_END
}
