#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

int
fn (OPJ_UINT32 i, OPJ_INT32 * __restrict c0, OPJ_UINT32 n,
    OPJ_INT32 * __restrict c2, OPJ_INT32 * __restrict c1)
{
  for (i = 0; i < n; ++i)
    {
      OPJ_INT32 r = c0[i];
      OPJ_INT32 g = c1[i];
      OPJ_INT32 b = c2[i];
      OPJ_INT32 y =
	opj_int_fix_mul (r, 2449) + opj_int_fix_mul (g,
						     4809) +
	opj_int_fix_mul (b, 934);
      OPJ_INT32 u =
	-opj_int_fix_mul (r, 1382) - opj_int_fix_mul (g,
						      2714) +
	opj_int_fix_mul (b, 4096);
      OPJ_INT32 v =
	opj_int_fix_mul (r, 4096) - opj_int_fix_mul (g,
						     3430) -
	opj_int_fix_mul (b, 666);
      c0[i] = y;
      c1[i] = u;
      c2[i] = v;
    }
}
