#include <stdint.h>
#include <stdio.h>




typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

int
fn (OPJ_UINT32 tile_w, OPJ_INT32 * __restrict tiledp, OPJ_UINT32 cblk_w,
    OPJ_UINT32 i, OPJ_UINT32 j, OPJ_INT32 * __restrict datap)
{
  for (i = 0; i < cblk_w; ++i)
    {
      OPJ_INT32 tmp = tiledp[(j * tile_w) + i];
      datap[(j * cblk_w) + i] = tmp << (7 - 1);
    }
}
