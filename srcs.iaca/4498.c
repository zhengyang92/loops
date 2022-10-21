#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * const d1, const uint16_t * c0_data, const uint16_t * c2_data,
    const int d0_signed_linesize, const int c0_shift_w, const int slicew_end,
    const int slicew_start, int x, const int d1_signed_linesize,
    const int limit, uint16_t * const d0, const int d2_signed_linesize,
    const int c2_shift_w, const int c1_shift_w, const uint16_t * c1_data,
    int intensity, const int max, uint16_t * const d2)
{
  for (x = slicew_start; x < slicew_end; x++)
     { IACA_START
      const int c0 =
	((c0_data[x >> c0_shift_w]) >
	 (limit) ? (limit) : (c0_data[x >> c0_shift_w]));
      const int c1 = c1_data[x >> c1_shift_w];
      const int c2 = c2_data[x >> c2_shift_w];
      update16 (d0 + d0_signed_linesize * c0 + x, max, intensity, limit);
      *(d1 + d1_signed_linesize * c0 + x) = c1;
      *(d2 + d2_signed_linesize * c0 + x) = c2;
} IACA_END }
