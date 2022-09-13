#include <stdint.h>
#include <stdio.h>




typedef VP8Random;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * const g_ptr, uint8_t * const dst_y, int i, int width,
    const uint8_t * const r_ptr, const uint8_t * const b_ptr,
    VP8Random * const rg, int j, int step)
{
  for (i = 0, j = 0; i < width; i += 1, j += step)
    {
      dst_y[i] = RGBToY (r_ptr[j], g_ptr[j], b_ptr[j], rg);
    }
}
