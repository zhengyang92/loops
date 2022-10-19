#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (const uint8_t * const g_ptr, int i, int width,
    const uint8_t * const r_ptr, const uint8_t * const b_ptr, int rgb_stride,
    const uint8_t * const a_ptr, int j, uint16_t * dst)
{
  for (i = 0, j = 0; i < (width >> 1); i += 1, j += 2 * 4, dst += 4)
    {
      const uint32_t a =
	(((a_ptr + j)[0] + (a_ptr + j)[rgb_stride]) +
	 (((a_ptr + j) + 4)[0] + ((a_ptr + j) + 4)[rgb_stride]));
      int r, g, b;
      if (a == 4 * 0xff || a == 0)
	{
	  r =
	    LinearToGamma (GammaToLinear ((r_ptr + j)[0]) +
			   GammaToLinear ((r_ptr + j)[(4)]) +
			   GammaToLinear ((r_ptr + j)[rgb_stride]) +
			   GammaToLinear ((r_ptr + j)[rgb_stride + (4)]), 0);
	  g =
	    LinearToGamma (GammaToLinear ((g_ptr + j)[0]) +
			   GammaToLinear ((g_ptr + j)[(4)]) +
			   GammaToLinear ((g_ptr + j)[rgb_stride]) +
			   GammaToLinear ((g_ptr + j)[rgb_stride + (4)]), 0);
	  b =
	    LinearToGamma (GammaToLinear ((b_ptr + j)[0]) +
			   GammaToLinear ((b_ptr + j)[(4)]) +
			   GammaToLinear ((b_ptr + j)[rgb_stride]) +
			   GammaToLinear ((b_ptr + j)[rgb_stride + (4)]), 0);
	}
      else
	{
	  r = LinearToGammaWeighted (r_ptr + j, a_ptr + j, a, 4, rgb_stride);
	  g = LinearToGammaWeighted (g_ptr + j, a_ptr + j, a, 4, rgb_stride);
	  b = LinearToGammaWeighted (b_ptr + j, a_ptr + j, a, 4, rgb_stride);
	}
      dst[0] = r;
      dst[1] = g;
      dst[2] = b;
      dst[3] = a;
    }
}
