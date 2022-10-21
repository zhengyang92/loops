#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint32_t OPJ_UINT32;
typedef float OPJ_FLOAT32;
typedef double OPJ_FLOAT64;

int
fn (OPJ_UINT32 pNbComps, OPJ_UINT32 i, OPJ_UINT32 j, OPJ_UINT32 lIndex,
    OPJ_FLOAT64 * lNorms, OPJ_FLOAT32 * lMatrix, OPJ_FLOAT32 lCurrentValue)
{
  for (j = 0; j < pNbComps; ++j)
     { IACA_START
      lCurrentValue = lMatrix[lIndex];
      lIndex += pNbComps;
      lNorms[i] += lCurrentValue * lCurrentValue;
     } IACA_END
}
