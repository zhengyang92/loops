#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;
typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (int w, int i, int src_linesize, const uint8_t * src, int8_t * dir,
    uint16_t * dst)
{
  IACA_START for (i = 1; i < w - 1; i++)
    {
      const int gx =
	-1 * src[-src_linesize + i - 1] + 1 * src[-src_linesize + i + 1] -
	2 * src[i - 1] + 2 * src[i + 1] - 1 * src[src_linesize + i - 1] +
	1 * src[src_linesize + i + 1];
      const int gy =
	-1 * src[-src_linesize + i - 1] + 1 * src[src_linesize + i - 1] -
	2 * src[-src_linesize + i] + 2 * src[src_linesize + i] -
	1 * src[-src_linesize + i + 1] + 1 * src[src_linesize + i + 1];
      dst[i] = ((gx) >= 0 ? (gx) : (-(gx))) + ((gy) >= 0 ? (gy) : (-(gy)));
      dir[i] = get_rounded_direction (gx, gy);
}IACA_END}
