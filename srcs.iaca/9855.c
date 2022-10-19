#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

int
fn (OPJ_INT32 * lCurrentData, OPJ_INT32 ** lData, OPJ_INT32 * lMctPtr,
    OPJ_UINT32 pNbComp, OPJ_UINT32 j, OPJ_UINT32 k)
{
  for (k = 0; k < pNbComp; ++k)
    {
      *(lData[j]) += opj_int_fix_mul (*lMctPtr, lCurrentData[k]);
      ++lMctPtr;
    }
}
