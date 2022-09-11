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
fn (const Int iTrimBits, const unsigned int iThOff, const unsigned int iTh,
    Int iTemp1, Int k, const Int iModelBits, CAdaptiveScan * pScan,
    Int * pRLCoeffs, Int iRun, const PixelI * pCoeffs, Int iTemp,
    Int * pResidual, const Int iCount, Int iLevel)
{
  Int iNumNonzero = 0;
  for (k = 2; k < iCount; k++)
    {
      const Int sk = pScan[k].uScan;
      iLevel = pCoeffs[sk];
      if ((unsigned int) (iLevel + iThOff) >= iTh)
	{
	  iTemp1 = abs (iLevel);
	  iTemp = iTemp1 >> iModelBits;
	  pResidual[sk] = ((iTemp1 & iThOff) >> iTrimBits) * 2;
	  pScan[k].uTotal++;
	  if (pScan[k].uTotal > pScan[k - 1].uTotal)
	    {
	      CAdaptiveScan cTemp = pScan[k];
	      pScan[k] = pScan[k - 1];
	      pScan[k - 1] = cTemp;
	    }
	  pRLCoeffs[iNumNonzero * 2] = iRun;
	  pRLCoeffs[iNumNonzero * 2 + 1] = (iLevel < 0) ? -iTemp : iTemp;
	  iNumNonzero++;
	  iRun = 0;
	}
      else
	{
	  iRun++;
	  iTemp = -(iLevel < 0);
	  iLevel = ((iLevel + iTemp) >> iTrimBits) - iTemp;
	  iTemp = -(iLevel < 0);
	  pResidual[sk] = (iLevel ^ iTemp) * 4 + (6 & iTemp) + (iLevel != 0);
	}
    }
}
