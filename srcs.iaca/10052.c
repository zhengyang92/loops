#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (const uint8_t * const g_ptr, int i, int width,
    const uint8_t * const r_ptr, const uint8_t * const b_ptr, int rgb_stride,
    int j, uint16_t * dst, int step)
{
  for (i = 0, j = 0; i < (width >> 1); i += 1, j += 2 * step, dst += 4)
     { IACA_START
      dst[0] =
	LinearToGamma (GammaToLinear ((r_ptr + j)[0]) +
		       GammaToLinear ((r_ptr + j)[(step)]) +
		       GammaToLinear ((r_ptr + j)[rgb_stride]) +
		       GammaToLinear ((r_ptr + j)[rgb_stride + (step)]), 0);
      dst[1] =
	LinearToGamma (GammaToLinear ((g_ptr + j)[0]) +
		       GammaToLinear ((g_ptr + j)[(step)]) +
		       GammaToLinear ((g_ptr + j)[rgb_stride]) +
		       GammaToLinear ((g_ptr + j)[rgb_stride + (step)]), 0);
      dst[2] =
	LinearToGamma (GammaToLinear ((b_ptr + j)[0]) +
		       GammaToLinear ((b_ptr + j)[(step)]) +
		       GammaToLinear ((b_ptr + j)[rgb_stride]) +
		       GammaToLinear ((b_ptr + j)[rgb_stride + (step)]), 0);
     } IACA_END
}
