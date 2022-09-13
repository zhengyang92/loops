#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int c1_shift_h, const uint16_t * c2_data,
    const int d0_signed_linesize, const int d2_signed_linesize, const int max,
    const uint16_t * c1_data, const int d2_linesize, const uint16_t * c0_data,
    const int c1_linesize, const int mid, const int c0_shift_w, int x,
    uint16_t * d2_data, const int c2_shift_h, uint16_t * const d0,
    const int c1_shift_w, uint16_t * const d2, int y, const int src_h,
    const int c2_shift_w, uint16_t * d0_data, const int c2_linesize,
    const int c0_shift_h, const int c0_linesize, uint16_t * d1_data,
    uint16_t * const d1, const int d1_signed_linesize, const int d0_linesize,
    const int limit, const int d1_linesize, const int intensity)
{
  for (y = 0; y < src_h; y++)
    {
      const int c0 =
	((c0_data[x >> c0_shift_w]) >
	 (limit) ? (limit) : (c0_data[x >> c0_shift_w])) + mid;
      const int c1 =
	((c1_data[x >> c1_shift_w]) >
	 (limit) ? (limit) : (c1_data[x >> c1_shift_w])) - mid;
      const int c2 =
	((c2_data[x >> c2_shift_w]) >
	 (limit) ? (limit) : (c2_data[x >> c2_shift_w])) - mid;
      uint16_t *target;
      target = d0 + x + d0_signed_linesize * c0;
      update16 (target, max, intensity, limit);
      target = d1 + x + d1_signed_linesize * (c0 + c1);
      update16_cr (target, max, intensity, limit);
      target = d2 + x + d2_signed_linesize * (c0 + c2);
      update16_cr (target, max, intensity, limit);
      if (!c0_shift_h || (y & c0_shift_h))
	c0_data += c0_linesize;
      if (!c1_shift_h || (y & c1_shift_h))
	c1_data += c1_linesize;
      if (!c2_shift_h || (y & c2_shift_h))
	c2_data += c2_linesize;
      d0_data += d0_linesize;
      d1_data += d1_linesize;
      d2_data += d2_linesize;
    }
}
