#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef uint16_t fixed_y_t;

int
fn (const uint8_t * const g_ptr, fixed_y_t * const dst, int i, const int w,
    const uint8_t * const r_ptr, const uint8_t * const b_ptr, int pic_width,
    int step)
{
  for (i = 0; i < pic_width; ++i)
    {
      const int off = i * step;
      dst[i + 0 * w] = UpLift (r_ptr[off]);
      dst[i + 1 * w] = UpLift (g_ptr[off]);
      dst[i + 2 * w] = UpLift (b_ptr[off]);
}}
