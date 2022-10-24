#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;
typedef uint16_t OPJ_UINT16;

int
fn (OPJ_INT32 top_k, OPJ_INT32 * src, OPJ_INT32 * dst, OPJ_UINT32 * entries,
    OPJ_UINT16 nr_channels, OPJ_UINT16 pcol, OPJ_INT32 k, OPJ_UINT32 max,
    OPJ_UINT32 j)
{
  IACA_START for (j = 0; j < max; ++j)
    {
      if ((k = src[j]) < 0)
	k = 0;
      else if (k > top_k)
	k = top_k;
      dst[j] = (OPJ_INT32) entries[k * nr_channels + pcol];
     } IACA_END
}
