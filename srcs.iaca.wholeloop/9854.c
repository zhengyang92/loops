#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

int
fn (OPJ_UINT32 pNbComp, OPJ_UINT32 j, OPJ_INT32 ** lData,
    OPJ_INT32 * lCurrentData)
{
  IACA_START for (j = 0; j < pNbComp; ++j)
    {
      lCurrentData[j] = (*(lData[j]));
     } IACA_END
}
