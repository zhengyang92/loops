#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef short IDWTELEM;

int
fn (int y, const uint8_t * obmc, const int block_h, const int w, int x,
    int mb_y, const int obmc_stride, int mb_x, int y2, IDWTELEM * dst, int x2,
    const int h, const int block_w, uint8_t * src, const int ref_stride)
{
  int ab = 0;
  int aa = 0;
  for (x2 = ((x) > (0) ? (x) : (0));
       x2 < ((w) > (x + block_w) ? (x + block_w) : (w)); x2++)
    {
      int index =
	x2 - (block_w * mb_x - block_w / 2) + (y2 -
					       (block_h * mb_y -
						block_h / 2)) * obmc_stride;
      int obmc_v = obmc[index];
      int d;
      if (y < 0)
	obmc_v += obmc[index + block_h * obmc_stride];
      if (x < 0)
	obmc_v += obmc[index + block_w];
      if (y + block_h > h)
	obmc_v += obmc[index - block_h * obmc_stride];
      if (x + block_w > w)
	obmc_v += obmc[index - block_w];
      d = -dst[index] + (1 << (4 - 1));
      dst[index] = d;
      ab += (src[x2 + y2 * ref_stride] - (d >> 4)) * obmc_v;
      aa += obmc_v * obmc_v;
    }
}
