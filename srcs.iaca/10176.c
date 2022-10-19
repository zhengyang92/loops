#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char U8;
typedef int I32;
typedef struct tagCWMIQuantizer
{
  U8 iIndex;
  I32 iQP;
  I32 iOffset;
  I32 iMan;
  I32 iExp;
} tagCWMIQuantizer;
typedef long unsigned int size_t;
typedef int Bool;
typedef CWMIQuantizer;

int
fn (size_t iCh, size_t cCh, U8 cChMode, size_t iPos, Bool bScaledArith,
    Bool bShiftedUV, CWMIQuantizer ** pQuantizer)
{
  for (iCh = 0; iCh < cCh; iCh++)
    {
      if (iCh > 0)
	if (cChMode == 0)
	  pQuantizer[iCh][iPos] = pQuantizer[0][iPos];
	else if (cChMode == 1)
	  pQuantizer[iCh][iPos] = pQuantizer[1][iPos];
      remapQP (pQuantizer[iCh] + iPos,
	       (iCh > 0 && bShiftedUV == 1) ? 1 - 1 : 1, bScaledArith);
    }
}
