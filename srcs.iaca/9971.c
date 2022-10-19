#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint32_t rescaler_t;
typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (const int x_out_max, rescaler_t * const irow, uint8_t * const dst,
    int x_out, const uint32_t scale)
{
  for (; x_out < x_out_max; ++x_out)
    {
      const int v =
	(int) (((uint64_t) (irow[x_out]) * (scale) +
		((1ull << 32) >> 1)) >> 32);
      ((void) sizeof ((v >= 0 && v <= 255) ? 1 : 0), __extension__ (
								     {
								     if (v >=
									 0
									 && v
									 <=
									 255);
								     else
								     __assert_fail
								     ("v >= 0 && v <= 255",
								      "program.c",
								      378,
								      __extension__
								      __PRETTY_FUNCTION__);}
       ));
      dst[x_out] = v;
      irow[x_out] = 0;
    }
}
