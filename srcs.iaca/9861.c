#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

int
fn (OPJ_UINT32 tile_w, OPJ_INT32 * __restrict tiledp, OPJ_INT32 bandconst,
    OPJ_UINT32 cblk_w, OPJ_UINT32 i, OPJ_UINT32 j,
    OPJ_INT32 * __restrict datap)
{
  for (i = 0; i < cblk_w; ++i)
     { IACA_START
      OPJ_INT32 tmp = tiledp[(j * tile_w) + i];
      datap[(j * cblk_w) + i] =
	opj_int_fix_mul (tmp, bandconst) >> (11 - (7 - 1));
     } IACA_END
}
