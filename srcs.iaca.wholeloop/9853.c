#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;
typedef float OPJ_FLOAT32;

int
fn (OPJ_FLOAT32 * lMct, OPJ_INT32 * lCurrentMatrix, OPJ_UINT32 lNbMatCoeff,
    OPJ_UINT32 lMultiplicator, OPJ_UINT32 i)
{
  IACA_START for (i = 0; i < lNbMatCoeff; ++i)
    {
      lCurrentMatrix[i] =
	(OPJ_INT32) (*(lMct++) * (OPJ_FLOAT32) lMultiplicator);
     } IACA_END
}
