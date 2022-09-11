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
fn (const unsigned int iThOff, const unsigned int iTh, Int iTemp1, Int k,
    const Int iModelBits, CAdaptiveScan * pScan, Int * pRLCoeffs, Int iRun,
    const PixelI * pCoeffs, Int iTemp, Int * pResidual, const Int iCount,
    Int iLevel, const Int gRes[65])
{
  Int iNumNonzero = 0;
  for (k = 2; k < iCount; k++)
    {
      const Int sk = pScan[k].uScan;
      iLevel = pCoeffs[sk];
      if ((unsigned int) (iLevel + iThOff) >= iTh)
	{
	  const Int iSign = -(iLevel < 0);
	  iTemp1 = (iSign ^ iLevel) - iSign;
	  iTemp = iTemp1 >> iModelBits;
	  pResidual[sk] = (iTemp1 & iThOff) * 2;
	  pScan[k].uTotal++;
	  if (pScan[k].uTotal > pScan[k - 1].uTotal)
	    {
	      CAdaptiveScan cTemp = pScan[k];
	      pScan[k] = pScan[k - 1];
	      pScan[k - 1] = cTemp;
	    }
	  pRLCoeffs[iNumNonzero * 2] = iRun;
	  pRLCoeffs[iNumNonzero * 2 + 1] = (iTemp ^ iSign) - iSign;
	  iNumNonzero++;
	  iRun = 0;
	}
      else
	{
	  iRun++;
	  pResidual[sk] = gRes[(iLevel + 32)];
	}
    }
}
