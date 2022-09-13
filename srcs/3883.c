#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int32_t int32_t;

int
fn (int32_t * rgb2yuv, int luma_stride, int i,
    void (*ff_rgb24toyv12) (const uint8_t *, uint8_t *, uint8_t *, uint8_t *,
			    int, int, int, int, int, int32_t *), int width,
    uint8_t * dstY, const uint8_t * src, uint8_t * dstU, int src_stride,
    uint8_t dst[12], uint8_t * dstV)
{
  const int dst_stride = 6;
  for (i = 2; i < width - 2; i += 2)
    {
      dst[(0) * dst_stride + (0) * 3 + 0] =
	((unsigned int) (src[(-1) * src_stride + 1 * (0)]) +
	 (unsigned int) (src[(1) * src_stride + 1 * (0)])) >> (1 + 0);
      dst[(0) * dst_stride + (0) * 3 + 1] =
	(src[(0) * src_stride + 1 * (0)]) >> 0;
      dst[(0) * dst_stride + (0) * 3 + 2] =
	((unsigned int) (src[(0) * src_stride + 1 * (-1)]) +
	 (unsigned int) (src[(0) * src_stride + 1 * (1)])) >> (1 + 0);
      dst[(0) * dst_stride + (1) * 3 + 0] =
	((unsigned int) (src[(-1) * src_stride + 1 * (0)]) +
	 (unsigned int) (src[(-1) * src_stride + 1 * (2)]) +
	 (unsigned int) (src[(1) * src_stride + 1 * (0)]) +
	 (unsigned int) (src[(1) * src_stride + 1 * (2)])) >> (2 + 0);
      dst[(0) * dst_stride + (1) * 3 + 1] =
	((unsigned int) (src[(-1) * src_stride + 1 * (1)]) +
	 (unsigned int) (src[(0) * src_stride + 1 * (0)]) +
	 (unsigned int) (src[(0) * src_stride + 1 * (2)]) +
	 (unsigned int) (src[(1) * src_stride + 1 * (1)])) >> (2 + 0);
      dst[(0) * dst_stride + (1) * 3 + 2] =
	(src[(0) * src_stride + 1 * (1)]) >> 0;
      dst[(1) * dst_stride + (0) * 3 + 0] =
	(src[(1) * src_stride + 1 * (0)]) >> 0;
      dst[(1) * dst_stride + (0) * 3 + 1] =
	((unsigned int) (src[(0) * src_stride + 1 * (0)]) +
	 (unsigned int) (src[(1) * src_stride + 1 * (-1)]) +
	 (unsigned int) (src[(1) * src_stride + 1 * (1)]) +
	 (unsigned int) (src[(2) * src_stride + 1 * (0)])) >> (2 + 0);
      dst[(1) * dst_stride + (0) * 3 + 2] =
	((unsigned int) (src[(0) * src_stride + 1 * (-1)]) +
	 (unsigned int) (src[(0) * src_stride + 1 * (1)]) +
	 (unsigned int) (src[(2) * src_stride + 1 * (-1)]) +
	 (unsigned int) (src[(2) * src_stride + 1 * (1)])) >> (2 + 0);
      dst[(1) * dst_stride + (1) * 3 + 0] =
	((unsigned int) (src[(1) * src_stride + 1 * (0)]) +
	 (unsigned int) (src[(1) * src_stride + 1 * (2)])) >> (1 + 0);
      dst[(1) * dst_stride + (1) * 3 + 1] =
	(src[(1) * src_stride + 1 * (1)]) >> 0;
      dst[(1) * dst_stride + (1) * 3 + 2] =
	((unsigned int) (src[(0) * src_stride + 1 * (1)]) +
	 (unsigned int) (src[(2) * src_stride + 1 * (1)])) >> (1 + 0);
      ff_rgb24toyv12 (dst, dstY, dstV, dstU, 2, 2, luma_stride, 0, dst_stride,
		      rgb2yuv);
      src += 2 * 1;
      dstY += 2;
      dstU++;
      dstV++;
}}
